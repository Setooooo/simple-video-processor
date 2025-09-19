#pragma once
#include "xlog.h"
#include <map>
#include <string>
#include <functional>
#include <vector>

class XLOG_API UserInput
{
public:
	/// <summary>
	/// 启动控制台应用等待用户输入
	/// </summary>
	void Start(std::function<void(std::vector<std::string>)>init = [](std::vector<std::string>) {});

	//注册参数处理的回调函数
	UserInput& Reg(std::string key,
		std::function<void(const std::string&)> func) {
		key_funcs_[key] = func;
		return *this;
	}
	UserInput& RegTask(std::string key,
		std::function<void()> func) {
		task_funcs_[key] = func;
		return *this;
	}
private:
	//循环任务是否退出
	bool is_exit_{ false };

	//关键字映射函数表
	std::map<std::string,
		std::function<void (const std::string&)>//回调函数传递value
	>key_funcs_;
	//初始化函数
	//std::function<void()>init_func_ = [] {};

	//任务执行函数
	std::map<std::string,
		std::function<void()>
	>task_funcs_;
};

