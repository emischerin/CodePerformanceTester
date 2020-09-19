#pragma once
#include <vector>
#include <random>
#include <iostream>

#include "IMeasurement.h"

class CountingSortNegNum:public IMeasurement
{
public:
	CountingSortNegNum();
	void Execute();
	void InitData(unsigned int data_count,int min,int max);
	void PrintData();
	void PrintSortedData();
	bool Validate();
	unsigned int FindMax();
	void InverseSigns(std::vector<int>& v);

private:

	std::vector<int> data;
	std::vector<int> sorted_data;
};

