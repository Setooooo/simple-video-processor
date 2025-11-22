//
// Created by beHe on 25-9-1.
//

#include "LogFac.h"

#include <iostream>
// #include <bits/valarray_after.h>

#include "LogConsoleOutput.h"
#include "LogFileOutput.h"
#include "LogFileThreadOutPut.h"
#include "xlog_format.h"

using namespace std;

#define LOGFILE "log.txt"

void LogFac::Init(const std::string &confige_file) {
  logger_.SetFormat(make_unique<XLogFormat>());
  XConfig config;
  bool re = config.Read(confige_file);
  string log_type = "console";
  string log_file = LOGFILE;
  string log_level = "debug";
  if (re) {
    log_type = config.Get("log_type");
    log_file = config.Get("log_file");
    log_level = config.Get("log_level");
  }
  if (log_type == "file") {
    if (log_file.empty()) log_file = LOGFILE;
    auto fout = make_unique<LogFileOutput>();

    if (!fout->Open(log_file)) {
      cerr << "Open log file " << log_file << "FAIL"<< endl;
    }
    logger_.SetOutput(std::move(fout));
  }else if (log_type == "filethread") {
    if (log_file.empty()) log_file = LOGFILE;
    auto fout = make_unique<LogFileThreadOutPut>();

    if (!fout->Open(log_file)) {
      cerr << "Open log file " << log_file << "FAIL" << endl;
    }
    logger_.SetOutput(std::move(fout));
  }
  else {
    logger_.SetOutput(make_unique<LogConsoleOutput>());
  }
  if (log_level == "debug") {
    logger_.SetLevel(XLog::DEBUG);
  }else if (log_level == "info") {
    logger_.SetLevel(XLog::INFO);
  }else if (log_level == "error") {
    logger_.SetLevel(XLog::ERROR);
  }else if (log_level == "fatal") {
    logger_.SetLevel(XLog::FATAL);
  }

}

#include "xlog_format.h"
