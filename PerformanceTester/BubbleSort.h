#pragma once
#include <vector>
#include <random>
#include <iostream>
#include "IMeasurement.h"


class BubbleSort :  public IMeasurement
{
public:
	BubbleSort();
	void Execute();
	void InitData(unsigned int data_count, int min, int max);
	void PrintData();
	void PrintSortedData();

private: 
	std::vector<int> data;
	std::vector<int> sorted_data;

	void DoBubbleSort();
};

