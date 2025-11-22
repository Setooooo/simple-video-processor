//
// Created by beHe on 25-9-1.
//

#include "LogFileOutput.h"
#include <iostream>

using namespace std;

bool LogFileOutput::Open(
  const std::string &filename) {
  ofs_.open(filename,  std::ofstream::app);
  if (!ofs_.is_open()) {
    return false;
  }
  return true;
}

void LogFileOutput::Output(
  const std::string &log) {
  ofs_ << log << '\n';
}
