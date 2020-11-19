#include "MergeSort.h"

MergeSort::MergeSort()
{
	this->tag = "MergeSort";
}

void MergeSort::Execute()
{
	this->DoMergeSort(0,sorted_data.size() - 1);
}

void MergeSort::InitData(unsigned int data_count, int min, int max)
{
	if (data_count == 0) return;

	int val = 0;
	data.clear();
	sorted_data.clear();

	data.resize(data_count);
	sorted_data.resize(data_count);

	std::random_device rd;
	std::mt19937 rne(rd());
	std::uniform_int_distribution<int> uid(min, max);




	for (size_t i = 0; i < data_count; ++i) {
		val = uid(rne);
		data[i] = val;
		sorted_data[i] = val;
	}
}

void MergeSort::PrintData()
{
	for (size_t i = 0; i < data.size(); ++i) {
		std::cout << data[i] << " "; 
	}

	std::cout << std::endl;
}

void MergeSort::PrintSortedData()
{
	for (size_t i = 0; i < sorted_data.size(); ++i) {
		std::cout << sorted_data[i] << " ";
	}

	std::cout << std::endl;
}

void MergeSort::DoMergeSort(int low, int high)
{
	if (low < high) {
		int half = (low + high) / 2;
		DoMergeSort(low, half);
		DoMergeSort(half + 1, high);
		Merge(low, half, high);
	}
	
}

void MergeSort::Merge(int low,int mid, int high)
{
	int size1 = (mid - low) + 1;
	int size2 = high - mid;
	int counter1 = 0;
	int counter2 = 0;
	int counter_merged = low;


	std::vector<int> v1(size1);
	std::vector<int> v2(size2);

	for (int i = 0; i < size1; ++i) {
		v1[i] = sorted_data[i + low];
	}

	for (int i = 0; i < size2; ++i) {
		v2[i] = sorted_data[i + mid + 1];
	}

	while ((counter1 < size1) && (counter2 < size2)) {
		if (v1[counter1] <= v2[counter2]) {
			sorted_data[counter_merged++] = v1[counter1++];
		}
		else {
			sorted_data[counter_merged++] = v2[counter2++];
		}
	}

	while (counter1 < size1) sorted_data[counter_merged++] = v1[counter1++];
	while (counter2 < size2) sorted_data[counter_merged++] = v2[counter2++];

	 
}