//
// Created by beHe on 25-9-1.
//

#ifndef LOG_OUTPUT_H
#define LOG_OUTPUT_H
#include <string>


class LogOutput {
  public:
  virtual ~LogOutput() = default;

  virtual void Output(const std::string &log) = 0;
};

#endif //LOG_OUTPUT_H
