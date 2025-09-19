#pragma once
#include "xtask.h"
#include "xexec.h"
/// <summary>
/// 基于ffmpeg和ffplay工具实现的影视频模块
/// </summary>
class FFTask :
    public XTask
{
public:


  // 通过 XTask 继承
  bool Start(const Data&) override;

  int Progress() override;

  // 通过 XTask 继承
  bool Runing() override;

  // 通过 XTask 继承
  int TotalSec() override;

private:
  int total_sec_{ 0 };//视频总时长
  int progress_{ 0 };
  int at_now_{ 0 };


  XExec exec_;

  // 通过 XTask 继承
  void Clear() override;
};

