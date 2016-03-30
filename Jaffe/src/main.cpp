#include <iostream>

#include "net.h"

using namespace jaffe;
using std::cout;
using std::string;
using std::endl;

int main(){
	JNet net;

	// 读取配置文件并初始化网络
	net.Init("deploy.prototxt");

	return 0;
}