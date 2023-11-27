#include "core_pch.h"
#include "Core.h"

#include "Profiler.h"
#include "Logger.h"

namespace Core {

	Engine::Engine()
	{
		std::cout << "Engine Created.\n";
		
	}

	void Engine::Init()
	{
		PROFILE_FUNCTION();

		std::cout << "Engine Initalizing.\n";

		//TODO : Implement Logger to live the duration of the engine


		LOG("Test Logging");
	}

	void Engine::Exit()
	{
	
		std::cout << "Engine Shutdown.\n";
	}

}