#pragma once
#include <random>
#include <vector>
#include <iostream>
#include "IMeasurement.h"

/* The same as BestNElements but modified to work both with negative and positive signed ints  */

class BestNAllInt :public IMeasurement
{
public:
	BestNAllInt(size_t best_count);
	void Execute();
	void InitData(unsigned int data_count,int min,int max);
	void PrintData();
	void PrintResult();
private:
	size_t best_count;
	std::vector<int> data;
	std::vector<int> result;

	void SeparateNegativesAndPositives(const std::vector<int>& in, 
		std::vector<int>& negatives, std::vector<int>& positives);

	void SelectBestPositiveElements(std::vector<int>& v,int elem_count);

	void SelectBestNegativeElements(std::vector<int>& v, int elem_count);
		

	void BestElements();
};

