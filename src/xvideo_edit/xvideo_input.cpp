#include "xvideo_input.h"
#include <iostream>
#include "user_input.h"
#include <string>
#include <thread>
#include <xdir.h>

using namespace std;
void XVideoInput::Start(std::unique_ptr<XTask>task)
{
	cout << "test XVideo Input" << endl;
	UserInput user;
	XTask::Data data;

	user
		.RegTask("play", [&] {//播放视频处理函数
		data.type = "play";
		task->Start(data);
		})
		.RegTask("cv", [&] { // 处理任务函数
			cout << "cv task" << endl;
			cout << data.src << " "
				<< data.des << endl;
			data.type = "cv";

			if (XDir::isDir(data.src)) {
				XDir dir;
				auto files = dir.GetFiles(data.src);
				for (auto f : files) {

					XTask::Data d = data;
					d.src = f.path;
					if (!XDir::isDir(data.des)) {
						XDir::Create(data.des);
					}
					d.des = data.des + "/" + f.name;
					task->Clear();
					RunTask(*task, d);
				}
			}
			else {
				task->Clear();
				RunTask(*task, data);
			}
		})
		.Reg("-s", [&data](const string& s) {
		cout << "-s: " << s << endl;
		data.src = s;
			})
		.Reg("-d", [&data](const string& s) { //目标文件
		cout << "-d: " << s << endl;
		data.des = s;
			})
		.Reg("-b", [&data](const string& s) { //剪切开始秒
		data.begin_sec = stoi(s);
			})
		.Reg("-e", [&data](const string& s) { //剪切结束秒
		data.end_sec = stoi(s);
			})
		.Reg("-p", [&data](const string& s) { //加密
		if (s.empty()) {
			cout << "password is no" << flush;
		}
		else
			data.password = s;
			})
		.Reg("-dp", [&data](const string& s) { //解密
		if (s.empty()) {
			cout << "please input password" << endl;
			string pass;
			cin >> pass;
			data.password = s;
		}
		else {
			data.password = s;
			data.is_enc = false;
		}
			});
		


	user.Start([&](vector<string>para) {
		cout << "init task " << endl;
		data = XTask::Data();
		task->Clear();

		if (para.size() < 4) {
			if(para.size() > 1)
				data.src = para[1];
			if(para.size() > 2)
				data.des = para[2];
		}
		});
}

void XVideoInput::RunTask(XTask& task, const XTask::Data& data)
{
	task.Start(data);
	// 等待任务结束,显示进度
	int n = 0, p = -1;
	while (task.Runing()) {
		if ((n = task.Progress()) != p) {
			cout << "\r% " << task.Progress();
			p = n;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // 暂停 2 秒
	}
	cout << "\r% " << "100" << endl;
}
