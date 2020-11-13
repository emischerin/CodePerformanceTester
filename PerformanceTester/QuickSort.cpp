#include "QuickSort.h"

QuickSort::QuickSort()
{
	this->tag = "QuickSort";
}

void QuickSort::Execute()
{
	DoQuickSort(0, sorted_data.size() - 1);
}

void QuickSort::InitData(unsigned int data_count, int min, int max)
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

void QuickSort::PrintData()
{
	for (size_t i = 0; i < data.size(); ++i) {
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;
}

void QuickSort::PrintSortedData()
{
	for (size_t i = 0; i < sorted_data.size(); ++i) {
		std::cout << sorted_data[i] << " ";
	}

	std::cout << std::endl;
}

void QuickSort::Swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void QuickSort::DoQuickSort(int low, int high)
{
	if (low < high) {

		size_t partition = Partition(low, high);
		DoQuickSort(low, partition - 1);
		DoQuickSort(partition + 1, high);
	}
	
}

//int QuickSort::Partition(int low, int high)
//{
//	int max = v[high];
//	int i = low - 1;
//
//	for (int j = low; j < high; j++) {
//		if (sorted_data[j] <= max) { 
//			++i;
//			std::swap(sorted_data[i], sorted_data[j]);
//		}
//	}
//	std::swap(sorted_data[i + 1], sorted_data[high]);
//
//	return i + 1;
//}

int QuickSort::Partition(int low, int high)
{
	
	int pivot = low;

	for (size_t i = low; i < high; ++i) {
		if (sorted_data[i] <= sorted_data[high]) {
			std::swap(sorted_data[pivot], sorted_data[i]);
			pivot++;
		}
	}

	std::swap(sorted_data[pivot], sorted_data[high]);

	return pivot;

}

