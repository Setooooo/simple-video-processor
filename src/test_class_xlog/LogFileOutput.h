//
// Created by beHe on 25-9-1.
//

#ifndef LOG_FILE_OUTPUT_H
#define LOG_FILE_OUTPUT_H
#include <fstream>

#include "log_output.h"


class LogFileOutput:public LogOutput
{
public:
  bool Open(const std::string &filename);
  void Output(const std::string &log) override;
private:
  std::ofstream ofs_;
};



#endif //LOG_FILE_OUTPUT_H
