#pragma once

#include <iostream>
#include <fstream>
#include <istream>
#include <chrono>
class ProfileTimer;//predefinition

struct ProfileResult {
	std::string name = "Default";
	long long start = 0;
	long long end = 0;
	size_t threadID = 0;

	long long elapsed = 0;
};

//If profiling is defined
//define function PROFILE_SCOPE() -> Creates a ProfileTimer, profile on destructor(out of scope)
// -> call in any scope
// -> constructs a ProfileTimer in the scope which logs on destruction
//define function PROFILE_FUNCTION() -> Create ProfileTimer, profile on destructor(out of scope)
// -> call at start of function (not in subscope, this will fail)
//If profiling is not define
// -> define the same functions without any functionality

#define PROFILING 1
#ifdef PROFILING
	#define PROFILE_SCOPE(name) \
		ProfileTimer timer##__LINE__(name)
	#define PROFILE_FUNCTION() \
		PROFILE_SCOPE(__FUNCTION__)
#else
	#define PROFILE_SCOPE(name)
	#define PROFILE_FUNCTION()
#endif



class Profiler {
private:
	
	std::string m_filename = "results.json";
	std::ofstream m_out;
	std::mutex m_mutex;
	std::vector<ProfileResult> m_results;

	Profiler() { /*write json header*/
		m_out = std::ofstream(GetFilename(), std::ios::out | std::ios::app);
		WriteHeader();
	};
	~Profiler() { /*Write json footer*/
		WriteFooter();
		m_out.close();
	};
public:
	
	std::string GetFilename() {
		std::string t = "results_";
		std::string datetime = "0.0.1.23.4.2";
		t.append(datetime);
		t.append(".json");

		return t;
	}

	void WriteHeader() {
		m_out << "{\n\"otherData\" : {},\n\"traceEvents\":[\n";
	}
	void WriteFooter() {
		m_out << "]}\n";
	}

	void WriteProfile(const ProfileResult& result) {

		if (m_results.size() > 0) {
			m_out << ",\n";
		}

		/*write result to json*/
		m_results.push_back(result);

		m_out << "{";
		m_out << "\"cat\" : \"function\",\n";
		m_out << "\"dur\" : " << (result.elapsed) << ",\n";
		m_out << "\"name\" : \"" << result.name << "\",\n";
		m_out << "\"ph\": \"X\",\n";
		m_out << "\"pid\": 0,\n";
		m_out << "\"tid\":" << result.threadID << ",\n";
		m_out << "\"ts\":" << result.start << "\n";
		m_out << "}";
	}

	static Profiler& Instance() {
		static Profiler instance;
		return instance;
	}
};


class ProfileTimer {
private:
	long long m_start = 0;
	long long m_end = 0;
	long long m_elapsed = 0;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_stp;
	std::string m_name = "Default";
public:

	ProfileTimer(const std::string& name) {
		m_name = name;
		Start();
	};

	void Start() {
		m_stp = std::chrono::high_resolution_clock::now();
	}

	long long Elapsed() {

		auto etp = std::chrono::high_resolution_clock::now();
		m_start = std::chrono::time_point_cast<std::chrono::microseconds>(m_stp).time_since_epoch().count();
		m_end = std::chrono::time_point_cast<std::chrono::microseconds>(etp).time_since_epoch().count();
		return m_end - m_start;
	}
	ProfileResult GetResult() {
		ProfileResult m;
		m.name = m_name;
		m.elapsed = m_elapsed = Elapsed();
		m.start = m_start;
		m.end = m_start;
		return m;
	}
	~ProfileTimer() {
		Profiler::Instance().WriteProfile(GetResult());
	}

};