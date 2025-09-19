#include "xdir.h"
#include <filesystem>
#include <iostream>

using namespace std;

std::vector<XFile> XDir::GetFiles(const std::string& path)
{
  vector<XFile>files;
  //迭代目录
  auto itr = filesystem::recursive_directory_iterator(path);
  for (auto& p : itr) {
    if (p.is_directory()) continue;
    if (!p.is_regular_file()) continue;
    files.push_back({
      p.path().filename().string(),
      p.path().string(),
      p.path().extension().string()
      });
  }


   return files;
}

bool XDir::isDir(const std::string& path)
{
  return filesystem::is_directory(path);
}

bool XDir::Create(const std::string& path)
{
  return filesystem::create_directory(path);
}
