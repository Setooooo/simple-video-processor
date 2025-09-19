//
// Created by beHe on 25-9-1.
//

#include "XConfig.h"
#include <fstream>
#include <iostream>
using namespace std;

bool XConfig::Read(const std::string &file) {
  ifstream ifs(file);
  // ofstream ofs(file);
  if (!ifs.is_open()) {
    cout << "no config file or can't read" << endl;
    return false;
  }
  string line;

  while (getline(ifs, line)) {
    auto p = line.find("=");
    if (p == string::npos) { continue; }
    conf_[line.substr(0, p)] = line.substr(p + 1);
    // cout<<"pre: "<<line.substr(0, p)<<endl;
    // cout<<"last: "<<line.substr(p + 1)<<endl;
  }

  return true;
}

const std::string & XConfig::Get(const std::string &key) const {
  auto it = conf_.find(key);
  if (it == conf_.end()) {static const string empty_string=""; return empty_string; }
  return it->second;
}
