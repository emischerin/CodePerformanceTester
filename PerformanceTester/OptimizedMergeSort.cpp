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
	int l = low;
	int m = mid + 1;
	int pos = low;
	

	for (int i = low; i <= high; ++i) tmp[i] = sorted_data[i];


	//for (int i = low; i <= high; ++i) {
	//	if (tmp[l] <= tmp[m]) sorted_data[i] = tmp[l++];
	//}


	while ((l <= mid) && (m <= high)) {
		if (tmp[l] <= tmp[m]) {
			sorted_data[pos++] = tmp[l++];
		}
		else {
			sorted_data[pos++] = tmp[m++];
		}
	}

	while (l <= mid) sorted_data[pos++] = tmp[l++];
	while (m <= high) sorted_data[pos++] = tmp[m++];


}