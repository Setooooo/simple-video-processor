//
// Created by beHe on 25-9-1.
//
#include <iostream>

#include "LogFac.h"

// #include "LogConsoleOutput.h"
// #include "LogFileOutput.h"
// #include "logger.h"
// #include "xlog_format.h"
#include "XConfig.h"
using namespace std;

int main() {
// XConfig conf;
//   conf.Read("log.conf");

  LogFac::Instance().Init();


  LOGOUT(XLog::DEBUG,"hello world");
  LOGDEBUG("debug");
  LOGINFO("info");


  // Logger logger;
  // logger.SetFormat(new XLogFormat);
  // auto fout = new LogFileOutput();
  // cout<<fout->Open("test.log")<<'\n';
  // logger.SetOutput(fout);
  // // logger.SetOutput(new LogConsoleOutput);
  // // logger.SetLevel(XLog::INFO);
  // logger.Write(XLog::DEBUG,"test",__FILE__,__LINE__);
  // logger.Write(XLog::INFO,"test",__FILE__,__LINE__);
  // logger.Write(XLog::ERROR,"test",__FILE__,__LINE__);
  // logger.Write(XLog::FATAL,"test",__FILE__,__LINE__);

  // LogFileOutput logfile;
  // logfile.Open("test.txt");
  // logfile.Output("test file log");

  // LogConsoleOutput log;
  // log.Output("test");
  // XLogFormat xlog;
  // auto str = xlog.Format("debug","test XlogFormat format",
  //   __FILE__,__LINE__);
  // cout << str << endl;
}