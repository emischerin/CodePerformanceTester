#pragma once
#include <random>
#include <vector>
#include <iostream>
#include "IMeasurement.h"

/*Finding best elements in vector in O(n). Unfortunatelly works only with positive numbers.
  Can be really easily modified to work with negative.
*/

class BestNElements : public IMeasurement
{
public:
	BestNElements(size_t best_count);
	void Execute();
	void InitData(unsigned int data_count, unsigned int min, unsigned int max);
	void PrintData();
	void PrintResult();
private:
	size_t best_count; 
	std::vector<size_t> data;
	std::vector<size_t> result;

	void BestElements();
	
};

