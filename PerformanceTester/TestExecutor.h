#pragma once
#include <chrono>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "IMeasurement.h"
#include "Measurement.h"


class TestExecutor
{
public:
	void ExecImeasurement(IMeasurement& im);
	void PrintResults(); 
	void SortResultsByTag();
	
	void PrintMeanResults();

private:
	std::vector<Measurement> results;
	std::unordered_map<std::string, Measurement> average;
	static bool SortByTag(const Measurement& first, const Measurement& second);
	void CalculateMeanValues();
	

	void CalculateMeasurementsCountByTag(std::unordered_map<std::string,size_t>& counts_by_tag);
};

