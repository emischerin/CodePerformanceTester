#pragma once
#include <vector>
#include <random>
#include <iostream>
#include "IMeasurement.h"

/* This algorithm is just running randomized select N times */

class BestNRandSelect:public IMeasurement
{
public:
	BestNRandSelect(int best_count);
	void Execute() override;
	void InitData(int data_count, int min, int max);
	void PrintData();
	void PrintResult();
private:
	int best_count;
	std::vector<int> data;
	std::vector<int> result;

	int RandomizedPartition(int low,int high);

	int Partition(int low, int high);

	int RandomizedSelect(int low, int high, int search_index);


	void SelectBestN();
};

