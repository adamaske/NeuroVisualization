#include <core_pch.h>
#include "Logger.h"

Logger::Logger()
{
	std::cout << "Logger Created.\n";
}

void Logger::Log(LogMessage msg)
{
	std::cout << "Logger : " << msg.m_msg << "\n";

}

void Logger::Log(std::string msg)
{
}

void Logger::WriteHeader()
{
}

void Logger::WriteFooter()
{
}
