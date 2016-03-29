#include <iostream>

#include "Net.h"

using namespace std;

int main(){
	Net net;

	// 读取配置文件并初始化网络
	if(!net.SetFilePath("train_val.prototxt"))
		cout << "Failed to Read Net Parameter" << endl;
	net.Init();

	return 0;
}