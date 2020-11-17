#pragma once
#include <string>

class IMeasurement
{
public:
	
	 std::string tag;
	 virtual void Execute() = 0;
	
	 
};

