#include <core_pch.h>
#include "Logger.h"

Logger::Logger()
{
	std::cout << "Logger Created.\n";
}

LogResult Logger::Log(LogMessage msg)
{
	std::cout << "Logger : " << msg.m_msg << "\n";

	return LogResult();
}
