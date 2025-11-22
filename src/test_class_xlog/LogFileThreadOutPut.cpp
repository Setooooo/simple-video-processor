//
// Created by beHe on 25-9-10.
//

#include "LogFileThreadOutPut.h"

#include <iostream>
using namespace std;

void LogFileThreadOutPut::Output(const std::string &log) {
  {
    lock_guard<mutex> lck(mtx_queue_);
    queue_.emplace(log);
  }
  cv_.notify_one();
}

bool LogFileThreadOutPut::Open(const std::string &filename) {
  bool is_open = LogFileOutput::Open(filename);
  if (!is_open) {
    std::cout<<"multi thread opend file error "<<filename<<std::endl;
  }

  thread_ = thread(&LogFileThreadOutPut::Run, this);

  return is_open;

}

void LogFileThreadOutPut::Run() {
    while (!is_exit_) {
      string line;
      {
        std::unique_lock lck(mtx_queue_);
        cv_.wait(lck,[&]{return !queue_.empty()||is_exit_;});
        if (is_exit_) {
          break;
        }
        line = queue_.front();
        queue_.pop();
      }
      LogFileOutput::Output(line);
    }
  while (!queue_.empty()) {
    LogFileOutput::Output(queue_.front());
    queue_.pop();
  }
}

LogFileThreadOutPut::~LogFileThreadOutPut() {
  is_exit_ = true;
  if (thread_.joinable())
    thread_.join();
}
