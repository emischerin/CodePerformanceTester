#pragma once
#include <chrono>
#include <vector>
#include <iostream>
#include "IMeasurement.h"
#include "Measurement.h"


class TestExecutor
{
public:
	void ExecImeasurement(IMeasurement& im);
	void PrintResults(); 

private:
	std::vector<Measurement> results;
};

