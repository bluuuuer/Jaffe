#include <iostream>

#include "net.h"

using namespace std;

int main(){
	Net net;

	// 读取配置文件并初始化网络
	if(!net.setFilePath("train_val.prototxt"))
		cout << "Failed to Read Net Parameter" << endl;
	net.init();

	return 0;
}