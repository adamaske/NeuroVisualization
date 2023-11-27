#pragma once

#include <vector>


class Hippo {
private:



public:
	Hippo();

	void Init();

	//What should this do
	
	//1. Give me a shared memeory address and key

	//open new memeroy segment
	
	static Hippo& Instance() {
		static Hippo instance;
		return instance;
	}
};