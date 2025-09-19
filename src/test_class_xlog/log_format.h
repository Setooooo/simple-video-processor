//
// Created by beHe on 25-9-1.
//

#ifndef LOG_FORMAT_H
#define LOG_FORMAT_H
#include <string>

////日志格式化接口类

class LogFormat {
public:
  virtual ~LogFormat() = default;

  ///<summary>
  ///格式化日志转为字符串
  ///@param level 日志级别
  ///@param log 日志内容
  ///@param file 源码文件路径
  ///@param line 代码行号
  ///@return 格式化后的日志内容
  ///</summary>
  virtual std::string Format(
    const std::string& level,
    const std::string&log,
    const std::string&file,
    int line
    ) = 0;
};



#endif //LOG_FORMAT_H
