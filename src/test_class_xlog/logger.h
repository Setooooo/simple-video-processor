//
// Created by beHe on 25-9-1.
//

#ifndef LOGGER_H
#define LOGGER_H
#include <string>

#include "log_format.h"
#include "log_output.h"
#include <memory>
#include <utility>

enum class XLog {
  DEBUG,
  INFO,
  ERROR,
  FATAL
};

class Logger {
public:
  void Write(
    XLog level,
    const std::string &log,
    const std::string file,
    const int line
  );
  void SetOutput(std::unique_ptr<LogOutput>o) {
    output_ = std::move(o);
  }
  void SetFormat(std::unique_ptr<LogFormat>f) {
    format_ = std::move(f);
  }
  ~Logger() {

    output_ = nullptr;
    format_ = nullptr;
  }
  void SetLevel(XLog level) {
    log_level_ = level;
  }
private:
  std::unique_ptr<LogOutput> output_{nullptr};
  std::unique_ptr<LogFormat> format_{nullptr};


  //最低日志级别
  XLog log_level_{XLog::DEBUG};
};



#endif //LOGGER_H
