#include "user_input.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

static vector<string> Split(const string& s) {
	string tmp;
	vector<string> vec;
	istringstream is{ s };
	while (getline(is, tmp, ' ')) {
		if (tmp.empty())continue;
		vec.emplace_back(tmp);
	}
	return vec;
}

void UserInput::Start(std::function<void(vector<std::string>)>init)
{
	//cout << "test user_input" << endl;
	//接受用户的输入
		string input;
	while (!is_exit_) {
		cout << "\n>>"<<std::flush;
		//cin >> input;
		getline(cin, input);
		if (input.empty()) continue;
		// 用空格分隔字符串
		//for (auto& it : vec) cout << it << endl;
		//cout << input << endl;
			if (input == "exit")
				break;
		auto vec = Split(input);
		if (vec.empty()) continue;

		string type = vec[0];
		// 初始化任务
		init(vec);

		//参数处理
		for (int i = 1;i < vec.size();++i) {
			//判断是否是关键字
			auto& k = vec[i];
			auto fitr = key_funcs_.find(k);
			if (fitr != key_funcs_.end()) {
				if (vec.size() - 1 > i) {
					auto& v = vec[i + 1];
					if (key_funcs_.find(v) == key_funcs_.end()) {
						cout << k << ":" << v << endl;
						++i;
						fitr->second(v);
						continue;
					}
				}
				fitr->second("");
				cout << k << ":" << endl;
				//cout << k << endl;

			}

		}

		// 执行任务
		auto task = task_funcs_.find(type);
		if (task == task_funcs_.end()) {
			cout << type << " not support!" << endl;
		}
		else {
			task->second();
		}
	}
}
