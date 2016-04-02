#include <iostream>

#include "net.h"

using std::cin;
using namespace jaffe;

int main(){

	JNet<int> net;
	// 读取配置文件并初始化网络
	net.Init("train_val.prototxt");

	cin.get();
	
	return 0;
}