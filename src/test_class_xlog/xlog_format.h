//
// Created by beHe on 25-9-1.
//

#ifndef XLOG_FORMAT_H
#define XLOG_FORMAT_H
#include "log_format.h"


class XLogFormat :
  public LogFormat{
public:
std::string Format(const std::string &level, const std::string &log, const std::string &file, int line) override;

///<summary>
  ///格式化日志转为字符串
  ///@param level 日志级别
  ///@param log 日志内容
  ///@param file 源码文件路径
  ///@param line 代码行号
  ///</summary>

};



#endif //XLOG_FORMAT_H
