#include "BubbleSort.h"

BubbleSort::BubbleSort()
{
	this->tag = "BubbleSort";
}

void BubbleSort::Execute()
{
	DoBubbleSort();
}

void BubbleSort::InitData(unsigned int data_count, int min, int max)
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

void BubbleSort::PrintData()
{
	for (size_t i = 0; i < data.size(); ++i) {
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;
}

void BubbleSort::PrintSortedData()
{
	for (size_t i = 0; i < sorted_data.size(); ++i) {
		std::cout << sorted_data[i] << " ";
	}

	std::cout << std::endl;
}

void BubbleSort::DoBubbleSort()
{
	for (size_t i = 0; i < sorted_data.size(); ++i) {
		for (size_t j = 0; j < sorted_data.size(); ++j) {
			if (sorted_data[i] < sorted_data[j])
				std::swap(sorted_data[i], sorted_data[j]);
		}
	}
}
