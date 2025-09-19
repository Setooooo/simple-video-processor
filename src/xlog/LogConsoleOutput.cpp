//
// Created by beHe on 25-9-1.
//

#include "LogConsoleOutput.h"

#include <iostream>
#include <ostream>
using namespace std;
void LogConsoleOutput::Output(
  const std::string &log) {
  cout<<log << endl;
}
