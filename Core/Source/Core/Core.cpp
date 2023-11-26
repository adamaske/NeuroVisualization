#include "core_pch.h"
#include "Core.h"
#include "Profiler.h"
#include <chrono>
#include <thread>
namespace Core {

	static Logger* s_Logger;

	static Logger* GetLogger() {
		return s_Logger;
	}

	static LogResult Log() {

		auto result = s_Logger->Log(LogMessage());

		return result;
	}
	Engine::Engine()
	{
		std::cout << "Engine Created.\n";
		
	}

	void Engine::Init()
	{
		PROFILE_FUNCTION();

		std::cout << "Engine Initalizing.\n";

		//TODO : Implement Logger to live the duration of the engine
		auto logger = Logger();
		s_Logger = &logger;
		
		auto result = GetLogger()->Log(LogMessage("Log Test"));
		std::cout << result.success << "\n";
	}

	void Engine::Exit()
	{
	
		std::cout << "Engine Shutdown.\n";
	}

}