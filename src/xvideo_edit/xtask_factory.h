#pragma once

/// <summary>
/// 创建XTask对象
/// </summary>

#include <iostream>
#include <memory>
#include "xtask.h"

class XTaskFactory
{
public:
	static std::unique_ptr<XTask>Create(int type = 0);
};

