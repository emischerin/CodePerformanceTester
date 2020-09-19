#pragma once
#include <chrono>
#include<string>

class Measurement
{
public:
	std::string tag;
	std::chrono::nanoseconds ns;
	std::chrono::seconds seconds;
	std::chrono::milliseconds ms;
	std::chrono::hours h;
};

