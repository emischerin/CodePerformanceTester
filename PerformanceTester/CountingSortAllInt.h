#pragma once
#include "IMeasurement.h"
#include <vector>
#include <iostream>
#include <random>

class CountingSortAllInt : public IMeasurement
{
public:
	CountingSortAllInt();
	void Execute();
	void InitData(unsigned int data_count, int min, int max);
	void PrintData();
	void PrintSortedData();
private:
	
	std::vector<int> data;
	std::vector<int> sorted_data;

	void SeparateNegativesAndPositives(const std::vector<int>& in,
		std::vector<int>& negatives, std::vector<int>& positives);

	void SortPositiveElements(std::vector<int>& v, int elem_count);

	void SortNegativeElements(std::vector<int>& v, int elem_count);


	void BestElements();
};

