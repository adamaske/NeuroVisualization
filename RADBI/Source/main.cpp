#include "pch.h"
#include <fstream>
int main()
{
	std::fstream o("test_test.txt");
	o.close();

	auto eng = Core::Engine();
	eng.Init();

	//Create a robot

	//Create arduino / raspberry pi communicator / server / client

	//Create UE5 communicator / server / client / 

	std::cout << system("dir") << "\n";

	eng.Exit();

	return 0;
}