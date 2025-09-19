//
// Created by beHe on 25-9-1.
//

#ifndef XCONFIG_H
#define XCONFIG_H

#include <string>
#include <sstream>
#include <map>
#include <optional>
//读取ini的配置文件
/*
 * log.conf
 *
 *
 */

class XConfig {
public:
  /*
   *读取配置文件
   */
  bool Read(const std::string &file);
  const std::string &Get(const std::string &key) const;
  std::map<std::string,std::string>conf_;
};



#endif //XCONFIG_H
