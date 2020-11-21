#pragma once
#include<vector>
#include<random>
#include<iostream>
#include "IMeasurement.h"
class OptimizedMergeSort : public IMeasurement
{
public:

	OptimizedMergeSort();

	void Execute();
	void InitData(unsigned int data_count, int min, int max);
	void PrintData();
	void PrintSortedData();

private:
	std::vector<int> data;
	std::vector<int> sorted_data;
	std::vector<int> tmp;
	void DoMergeSort(int low, int high);
	void Merge(int low, int mid, int high);

};

