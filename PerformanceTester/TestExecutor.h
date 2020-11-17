#pragma once
#include <chrono>
#include <vector>
#include <iostream>
#include <algorithm>
#include "IMeasurement.h"
#include "Measurement.h"


class TestExecutor
{
public:
	void ExecImeasurement(IMeasurement& im);
	void PrintResults(); 
	void SortResultsByTag();


private:
	std::vector<Measurement> results;

	static bool SortByTag(const Measurement& first, const Measurement& second);

	void CalculateAverage();
};

