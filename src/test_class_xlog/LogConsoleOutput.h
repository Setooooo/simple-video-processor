//
// Created by beHe on 25-9-1.
//

#ifndef LOG_CONSOLE_OUTPUT_H
#define LOG_CONSOLE_OUTPUT_H
#include "log_output.h"


class LogConsoleOutput:
  public LogOutput{
public:
void Output(const std::string &log) override;
};



#endif //LOG_CONSOLE_OUTPUT_H
