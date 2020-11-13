#pragma once
#include <vector>
#include <random>
#include <iostream>
#include "IMeasurement.h"

class QuickSort :public IMeasurement
{
public:

	QuickSort();

	void Execute();
	void InitData(unsigned int data_count,int min,int max);
	void PrintData();
	void PrintSortedData();
private:
	std::vector<int> data;
	std::vector<int> sorted_data;

	void Swap(int* a,int* b);
	void DoQuickSort(int low, int high);
	int Partition(int low, int high);


};

