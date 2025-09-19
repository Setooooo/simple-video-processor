#pragma once
#include "xlog.h"
#include <string>
#include <queue>
#include <future>
#include <functional>

class XLOG_API XExec
{
public:
		/// <summary>
		/// 执行外部进程
		/// </summary>
		/// <param name="cmd">控制台命令</param>
		/// <param name="func">控制台输出回调,设置后不在写入缓存队列</param>
		/// <returns>打开命令管道是否成功</returns>
		bool Start(const char* cmd,
			std::function<void(const std::string&s)>func=nullptr);
		/// <summary>
		/// 任务是否还在执行
		/// </summary>
		/// <returns></returns>
		bool Runing();
		/// <summary>
		/// 获取控制台的输出
		/// </summary>
		/// <param name="out"></param>
		/// <returns>是否获得了输出</returns>
		bool GetOutput(std::string &out);
		bool Wait() { return fut_.get(); }
private:
	bool runing_ = false;

	// 缓存队列
	std::queue<std::string>outs_;

	//任务执行线程
	std::future<bool>fut_;

	std::mutex mux_;
};

