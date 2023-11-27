#pragma once

#define LOG(msg) \
	Logger::Instance().Log(msg)


enum GRADE{ PRINT, WARNING, ERROR };

struct LogMessage {
public:
	std::string m_msg = "Test";

	std::string time;

};
struct LogResult {
	bool success = true;
};

class Logger {
private:
	std::string m_filename = "results.json";
	std::ofstream m_out;

	long long m_start = 0;
	long long m_end = 0;
	long long m_elapsed = 0;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_stp;

public:
	Logger();

	void Log(LogMessage msg);
	void Log(std::string msg);

	void WriteHeader();
	void WriteFooter();

	static Logger& Instance() {
		static Logger instance;
		return instance;
	}
};