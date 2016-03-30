#include "net.h"

using namespace jaffe;

int main(){
	JNet<int> net;

	// 读取配置文件并初始化网络
	net.Init("deploy.prototxt");

	return 0;
}