#include "OptimizedMergeSort.h"




OptimizedMergeSort::OptimizedMergeSort()
{
	this->tag = "OptimizedMergeSort";
}

void OptimizedMergeSort::Execute()
{
	this->DoMergeSort(0, sorted_data.size() - 1);
}

void OptimizedMergeSort::InitData(unsigned int data_count, int min, int max)
{
	if (data_count == 0) return;

	int val = 0;
	data.clear();
	sorted_data.clear();

	data.resize(data_count);
	sorted_data.resize(data_count);
	tmp.resize(data_count);

	std::random_device rd;
	std::mt19937 rne(rd());
	std::uniform_int_distribution<int> uid(min, max);




	for (size_t i = 0; i < data_count; ++i) {
		val = uid(rne);
		data[i] = val;
		sorted_data[i] = val;
	}
}

void OptimizedMergeSort::PrintData()
{
	for (size_t i = 0; i < data.size(); ++i) {
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;
}

void OptimizedMergeSort::PrintSortedData()
{
	for (size_t i = 0; i < sorted_data.size(); ++i) {
		std::cout << sorted_data[i] << " ";
	}

	std::cout << std::endl;
}

void OptimizedMergeSort::DoMergeSort(int low, int high)
{
	if (low < high) {
		int half = (low + high) / 2;
		DoMergeSort(low, half);
		DoMergeSort(half + 1, high);
		Merge(low, half, high);
	}

}

void OptimizedMergeSort::Merge(int low, int mid, int high)
{
	int size1 = (mid - low) + 1;
	int size2 = high - mid;
	int counter1 = 0;
	int counter2 = 0;
	int counter_merged = low;
	

	for (int i = low; i <= high; ++i) tmp[i] = sorted_data[i];

	while ((counter1 < size1) && (counter2 < size2)) {
		if (tmp[counter1] <= tmp[counter2]) {
			sorted_data[counter_merged++] = tmp[counter1++];
		}
		else {
			sorted_data[counter_merged++] = tmp[counter2++];
		}
	}

	while (counter1 < size1) sorted_data[counter_merged++] = tmp[counter1++];
	while (counter2 < size2) sorted_data[counter_merged++] = tmp[counter2++];


}