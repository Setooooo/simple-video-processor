#include "xexec.h"
#include <iostream>
#include <string>

using namespace std;
#ifdef _WIN32// _WIN32
#else
#define _popen popen
#endif 


bool XExec::Start(const char* cmd,
	function<void(const string&s)>func) {
	cout << "Start cmd:" << cmd << endl;
	//从定向错误输出到标准错误输出
	string tmp = cmd;
	tmp += " 2>&1";//2 错误输出 cerr 1 标准输出 cout
	auto fp = _popen(tmp.c_str(), "r");//获取标准输出
	if (!fp) return false;
	//runing_ = true;

	fut_ = async(std::launch::async,[fp,this,func]{
			string tmp;
			char c = 0;
			while (c = fgetc(fp))
			{
				if (c == EOF) break;

				// /r回到当前行的开头
				// /n到下一行的开头
				if (c == '\n' || c == '\r') {
					//cout << tmp << endl; 
					if (tmp.empty())continue;
					{
						if (func) {
							func(tmp);
						}
						else {
							lock_guard<mutex> lock(mux_);
							outs_.emplace(tmp);
						}
					}

					tmp.clear();
					continue;
				}
				tmp += c;
			}
			_pclose(fp);
			return true;
		}
	);
	
	return true;
}

bool XExec::Runing()
{
	if (!fut_.valid()) {
		return false;
	}
	auto status = fut_.wait_for(std::chrono::seconds(0));
	if (status == std::future_status::timeout) {
		return true;
	}
	return false;
}


bool XExec::GetOutput(std::string& out)
{
	lock_guard<mutex> lock(mux_);
	if (outs_.empty())return false;
	//cout << outs_.front() << endl;
	out = std::move(outs_.front());
	outs_.pop();
	return true;
}
