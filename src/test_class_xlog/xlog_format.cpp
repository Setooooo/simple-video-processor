//
// Created by beHe on 25-9-1.
//

#include "xlog_format.h"
#include <sstream>

using namespace std;


std::string XLogFormat::Format(const std::string &level, const std::string &log, const std::string &file, int line) {
  stringstream ss;
  ss
  << level << " "
  << log << " "
  << file << ":"
  << line ;
  return ss.str();
}
