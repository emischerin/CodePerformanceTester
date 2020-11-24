#pragma once
#include "IMeasurement.h"
#include <iostream>
#include <random>
#include <vector>

/*Return best n elements in vector. Algorithm based on counting sort*/
class BElementsCounts:public IMeasurement
{
public:
	BElementsCounts(size_t elements_count);

	void Execute();
	void InitData(unsigned int data_count, int min, int max);
	void PrintData();
	void PrintSortedData();
private:
	size_t elements_count;
	std::vector<int> data;
	std::vector<int> result;

	void BestNElements(size_t elem_count);
};

