#pragma once
#include <memory>
#include "xtask.h"
/// <summary>
/// 获取用户的输入,执行视频处理任务
/// </summary>
class XVideoInput
{
public:
	/// <summary>
	/// 开始接受用户输入,并调用task执行任务
	/// </summary>
	void Start(std::unique_ptr<XTask>);
private:
	void RunTask(XTask& task,const XTask::Data& data);
};

