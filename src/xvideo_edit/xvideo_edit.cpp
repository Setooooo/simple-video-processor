
#include <iostream>
#include "xtask_factory.h"
#include "xvideo_input.h"
#include "xdir.h"
int main()
{
	/*
	{
		XDir d;
		auto f = d.GetFiles(".");
		for (auto& p : f) {
			std::cout << p.name << std::endl;
		}
	}*/
	
	XVideoInput input;
	input.Start(XTaskFactory::Create());


	/*
	auto task = XTaskFactory::Create();
	XTask::Data data;
	data.src = "test.mp4";
	data.des = "out.mp4";
	data.type = "cv";
	task->Start(data);
	*/
	//system("ffplay out.mp4");
	//system("ffmpeg -y -i Mountain_Fog_3840x2160.mp4 out.mp4");
}


