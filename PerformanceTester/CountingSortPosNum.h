#pragma once
#include <vector>
#include <unordered_map>
#include <random>
#include <iostream>
#include "IMeasurement.h"

class CountingSortPosNum : public IMeasurement
{
public:
	CountingSortPosNum();
	void Execute();
	void InitData(unsigned int data_count, unsigned int min, unsigned int max);
	void PrintData();
	void PrintSortedData();
	unsigned int FindMax();

private:
	
	std::vector<unsigned int> data;
	std::vector<unsigned int> sorted_data;
};

