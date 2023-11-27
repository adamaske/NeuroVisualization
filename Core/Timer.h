#pragma once

#include <iostream>
#include <fstream>
#include <istream>
#include <chrono>

class Timer {
private:
	long long m_start = 0;
	long long m_end = 0;
	long long m_elapsed = 0;

	std::chrono::time_point<std::chrono::high_resolution_clock> m_stp;

	Timer(bool start = true);

	void Start();

	void Stop();

	void Elapsed();
};