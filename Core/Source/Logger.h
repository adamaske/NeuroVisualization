#pragma once


enum GRADE{ PRINT, WARNING, ERROR };

struct LogMessage {
public:
	std::string m_msg = "Test";
};
struct LogResult {
	bool success = true;
};

class Logger {
public:
	Logger();

	LogResult Log(LogMessage msg);

};