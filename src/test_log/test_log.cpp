// test_log.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "xlog.h"
#include "LogFac.h"
#include "xexec.h"
#include "user_input.h"
using namespace std;

int main()
{

  UserInput userinput;
  userinput
    .Reg("-s", [](const std::string& s) {
    cout << "-----src:" << s << endl;
      })
    .Reg("-d", [](const std::string& s) {
    cout << "-----des:" << s << endl;
      })
    .Reg("-p", [](const string& s) {
    cout << "-----password: " << s << endl;
      })
    //注册任务处理函数
    .RegTask("cv", [] {
    cout << "@@@@  cv task!  @@@@" << endl;
      });
  userinput.Star();



  //XLOGINIT();
  //LOGDEBUG("test xlog")


  /*
  XExec exec;
  std::cout << exec.Start("ping 127.0.0.1 ") << std::endl;

  std::string out;
  while (exec.Runing()) {
    //std::cout << "this is running" << std::endl;
    if (exec.GetOutput(out)) {
      std::cout << out << std::endl;
    }
    else {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  }
  while (exec.GetOutput(out)) {
    std::cout << out << std::endl;
  }
  */
  //Cxlog c;
  //std::cout << "Hello World!\n";
}

