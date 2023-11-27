#pragma once
class Logger;
namespace Core {

#define ARRAYSIZEM(b) (sizeof(b)/sizeof(b[0]))

	class Engine {


	public:
		Engine();

		void Init();

		void Exit();

	};
}