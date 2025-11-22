//
// Created by beHe on 25-9-1.
//

#include "logger.h"
#include "log_format.h"
#include "log_output.h"
using namespace std;

/**
 * 写一个日志内容
 * @param level 日志等级
 * @param log 日志内容
 * @param file 日志发生的文件
 * @param line 日志发生所在的行号
 */
void Logger::Write(XLog level, const std::string &log, const std::string file, const int line) {
if (log_level_>level) {
  return;
}
  string levelstr = "debug";
  switch (level) {
    case XLog::DEBUG:
      levelstr = "debug";
      break;
      case XLog::INFO:
      levelstr = "info";
      break;
      case XLog::ERROR:
      levelstr = "error";
      break;
      case XLog::FATAL:
      levelstr = "fatal";
      break;
  }

  auto str = format_ -> Format(levelstr, log, file, line);
  output_ -> Output(str);

}
