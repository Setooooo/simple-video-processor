//
// Created by beHe on 25-9-10.
//

#ifndef LOGFILETHREADOUTPUT_H
#define LOGFILETHREADOUTPUT_H
#include <condition_variable>
#include <queue>
#include <thread>

#include "LogFileOutput.h"


class LogFileThreadOutPut :public LogFileOutput{
public:
  void Output(const std::string &log) override;
  bool Open(const std::string &filename);
  void Run();
  ~LogFileThreadOutPut();
private:
  std::thread thread_;
  std::mutex mtx_file_;
  std::mutex mtx_queue_;
  std::atomic<bool> is_exit_;
  std::queue<std::string> queue_;
  std::condition_variable cv_;
};



#endif //LOGFILETHREADOUTPUT_H
