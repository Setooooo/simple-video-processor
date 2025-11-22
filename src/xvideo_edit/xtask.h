#pragma once
#include <string>
/// <summary>
/// 影视频处理接口
/// </summary>
/// 




class XTask 
{
public:
	struct Data
	{
		std::string type;// 任务类型
		std::string src; // 源文件
		std::string des; // 目标文件
		std::string password;//加解密密钥
		bool is_enc{ true };// 是否是加密 false表示解密
		int begin_sec{ 0 };
		int end_sec  { 0 };
	};
	/// <summary>
	/// 开启影视频处理任务,立刻返回,在线程中处理
	/// </summary>
	/// <param name="">任务配置参数</param>
	/// <returns>任务是否正常执行</returns>
	virtual bool Start(const Data&) = 0;
	/// <summary>
	/// 获取任务进度 0 ~ 100
	/// </summary>
	/// <returns>0~100 进度值</returns>
	virtual int Progress() = 0;
	/// <summary>
	/// 任务是否处理结束
	/// </summary>
	/// <returns></returns>
	virtual bool Runing() = 0;

	/// <summary>
	/// 视频总时长秒
	/// </summary>
	/// <returns></returns>
	virtual int TotalSec() = 0;

	virtual void Clear() = 0;
};