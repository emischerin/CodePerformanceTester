#include "SedgewickMergeSort.h"

SedgewickMergeSort::SedgewickMergeSort()
{
	this->tag = "SedgewickMergeSort";
}

void SedgewickMergeSort::Execute()
{
	this->DoMergeSort(0, sorted_data.size() - 1);
}

void SedgewickMergeSort::InitData(unsigned int data_count, int min, int max)
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

void SedgewickMergeSort::PrintData()
{
	for (size_t i = 0; i < data.size(); ++i) {
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;
}

void SedgewickMergeSort::PrintSortedData()
{
	for (size_t i = 0; i < sorted_data.size(); ++i) {
		std::cout << sorted_data[i] << " ";
	}

	std::cout << std::endl;
}

void SedgewickMergeSort::DoMergeSort(int low, int high)
{
	if (high <= low) return;

	int mid = low + (high - low) / 2;
	DoMergeSort(low, mid);
	DoMergeSort(mid + 1, high);
	Merge(low, mid, high);

}

void SedgewickMergeSort::Merge(int low, int mid, int high)
{
	int l = low, j = mid + 1;

	for (int i = low; i <= high; ++i) tmp[i] = sorted_data[i]; 

	for (int i = low; i <= high; ++i) {
		if (l > mid) sorted_data[i] = tmp[j++];
		else if (j > high) sorted_data[i] = tmp[l++];
		else if (Less(tmp[j], tmp[l])) sorted_data[i] = tmp[j++];
		else sorted_data[i] = tmp[l++];
	}


}

inline bool SedgewickMergeSort::Less(const int& a,const int& b)
{
	return a < b;
}
