//
// Created by beHe on 25-9-1.
//

#ifndef LOGFAC_H
#define LOGFAC_H

#include <string>
#include "logger.h"
#include "XConfig.h"
#include "xlog.h"

//logger工厂类
//维护logger生命周期
//构建logger
class XLOG_API LogFac {
public:
  static LogFac& Instance() {
    static LogFac instance;
    return instance;
  }

  void Init(const std::string &confige_file = "log.conf");
  Logger& logger(){return logger_;}

private:
  LogFac(){};
  Logger logger_;

};
#define XLOGINIT() LogFac::Instance().Init();
#define LOGOUT(l,s)   LogFac::Instance().logger().Write(l,s,__FILE__,__LINE__);
#define LOGDEBUG(s)   LOGOUT(XLog::DEBUG,s)
#define LOGINFO(s)    LOGOUT(XLog::INFO,s)
#define LOGERROR(s)   LOGOUT(XLog::ERROR,s)
#define LOGFATAL(s)   LOGOUT(XLog::FATAL,s)

#endif //LOGFAC_H
