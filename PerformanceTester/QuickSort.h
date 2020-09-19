#pragma once
#include <vector>

class QuickSort
{
public:
	void Execute();
	void InitData(unsigned int data_count,int min,int max);
	void PrintData();
	void PrintSortedData();
private:
	std::vector<int> data;
	std::vector<int> sorted_data;

	void Swap(int& a,int& b);
	void DoQuickSort(std::vector<int>& v, int p, int r);
	int Partition(std::vector<int>& v, int p, int r);


};

