#pragma once

#include <vector>
#include <unordered_map>
#include <random>
#include <iostream>
#include "IMeasurement.h"



class CountingSortUmap:public IMeasurement
{
public:


	 void Execute();
	 void InitData(unsigned int data_count,int min,int max);
	 void PrintData();


private:
	std::vector<int> data;
	std::vector<int> sorted_data;
	
};

