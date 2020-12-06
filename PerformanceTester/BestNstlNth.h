#pragma once
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include "IMeasurement.h"


class BestNstlNth:public IMeasurement
{
public:
	BestNstlNth(size_t best_count);
	void Execute() override;
	void InitData(unsigned int data_count, int min, int max);
	void PrintData();
	void PrintSortedData();
	void PrintResult();
private:
	size_t best_count;
	std::vector<int> data;
	std::vector<int> sorted_data;
	std::vector<int> result;


	void SelectBestN();

	
};

