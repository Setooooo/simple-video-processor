#include "fftask.h"
#include <cctype>
#include <iostream>
#include "xexec.h"
using namespace std;

#define DEFAULT_PASS "1e5fb604bdba498ac30ed081b8d82187"

static string QuoteArg(const string& value) {
  if (value.empty()) {
    return "\"\"";
  }
  if (value.find_first_of(" \t\"") == string::npos) {
    return value;
  }
  string quoted = "\"";
  for (const char c : value) {
    if (c == '"') {
      quoted += "\\\"";
      continue;
    }
    quoted += c;
  }
  quoted += '"';
  return quoted;
}

static string MergePassword(const string& password) {
  string pass = DEFAULT_PASS;
  for (size_t i = 0; i < password.size() && i < pass.size(); ++i) {
    pass[i] = password[i];
  }
  return pass;
}


static bool checkTime(const string& str) {
  for (const auto& c : str) {
    if (std::isdigit(static_cast<unsigned char>(c)) || c == ':')
      continue;
    else
      return false;
  }
  return true;
}
static int TimeToSec(const string& s,int now) {
  // 00:02:31
  if (s.size() < 8)return 0;
  if (!checkTime(s)) return now;

  int h = stoi(s.substr(0, 2));
  int m = stoi(s.substr(3, 2));
  int sec = stoi(s.substr(6, 2));
  return h * 3600 + m * 60 + sec;
}

bool FFTask::Start(const Data& para)
{
  cout << "test Start" << endl;
  ///////////////////////////
  //视频剪切
  // ffmpeg -y -i test.mp4 out.mp4
  // ffmpeg -y -ss 10 -t 5 -i Mountain_Fog_3840x2160.mp4 out.mp4
  // -ss必须在-i之前
  //cv -s Mountain_Fog_3840x2160.mp4 -d out.mp4 -b 10 - e 15
  string cmd = "ffmpeg -y";
  bool is_play = para.type == "play";

  if (is_play) {
    cmd = "ffplay";
  }

  if (para.begin_sec > 0) {
    cmd += " -ss " + to_string(para.begin_sec);
  }
  if (para.end_sec > 0) {
    int  t = para.end_sec - para.begin_sec;
    if (t > 0)
      cmd += " -t " + to_string(t);
  }
  /////////////////////////
  // 视频解密 密钥必须在-i 之前
  if (!is_play && !para.is_enc) {
    if (!para.password.empty()) {
      cmd += " -decryption_key " + MergePassword(para.password);
    }
  }
  // KEY//1e5fb604bdba498ac30ed081b8d82187
  // KID//2d06cf4e86cdc424dc47d0e08a28e387
  // 加密视频 密钥必须在-i之后
  //ffmpeg -decryption_key 1e5fb604bdba498ac30ed081b8d82187 -i out.mp4 -vcodec copy -acodec copy decrypted.mp4
  if (!para.src.empty()) {
    if (is_play) {
      cmd += " " + QuoteArg(para.src);
    }
    else {
      cmd += " -i " + QuoteArg(para.src);
    }
  }




  if (!is_play && para.is_enc) {
    string pass = MergePassword(para.password);
    if (!para.password.empty()) {
    cmd += " -encryption_scheme cenc-aes-ctr -encryption_kid 2d06cf4e86cdc424dc47d0e08a28e387";
    cmd += " -encryption_key " + pass;
    }  else {
    cmd += " -encryption_scheme cenc-aes-ctr -encryption_kid 2d06cf4e86cdc424dc47d0e08a28e387";
    cmd += " -encryption_key " + pass;
  }
  }

  //输出文件
  if(!para.des.empty() && !is_play)
    cmd += " " + QuoteArg(para.des);

  cout << "cmd: " << cmd << endl;

  return exec_.Start(cmd.c_str(), [this](const string& s) {
    //cout << s << endl;
    // 1 获取视频时长
    //cv -s Mountain_Fog_3840x2160.mp4 -d out.mp4
    if (total_sec_ <= 0) {
      auto pos = s.find("Duration: ");
      if (pos != string::npos) {
          string tmp = s.substr(pos + 10, 8);
          total_sec_ = TimeToSec(tmp,at_now_);
        //cout << tmp << endl;
        
        //cout << "total_sec_= " << TotalSec()<<" s" << endl;
      }
      else {
        //cout << "can't find time length" << endl;
      }
    }
    //2 获取进度
    {
      auto pos = s.find("time=");
      if (pos != string::npos) {
        string tmp = s.substr(pos+5,8);
        at_now_ = TimeToSec(tmp,at_now_);

        if(total_sec_>0)
          progress_ = at_now_ * 100 / total_sec_;
        return;
      }
    }
    });
}

int FFTask::Progress()
{
    return progress_;
}

int FFTask::TotalSec()
{
  return total_sec_;
}

void FFTask::Clear()
{
  total_sec_ = 0;
  progress_ = 0;
  at_now_ = 0;

}

bool FFTask::Runing()
{
  return exec_.Runing();
}
