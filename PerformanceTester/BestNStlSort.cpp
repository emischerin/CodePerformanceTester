#include "BestNStlSort.h"

BestNStlSort::BestNStlSort(size_t best_count)
{
	this->tag = "Best N StlSort";
	this->best_count = best_count;
}

void BestNStlSort::Execute()
{
	this->SelectBestN();
}

void BestNStlSort::InitData(unsigned int data_count, int min, int max)
{
	if (data_count < best_count)
		throw("Number of best elements could not be more than number of all elements");

	data.clear();
	result.clear();

	int random_int;
	std::random_device rd;
	std::mt19937 rne(rd());
	std::uniform_int_distribution<int> uid(min, max);



	for (unsigned int i = 0; i < data_count; ++i) {
		random_int = uid(rne);
		data.push_back(random_int);
		sorted_data.push_back(random_int);
	}
}

void BestNStlSort::PrintData()
{
	for (int s : data) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

void BestNStlSort::PrintResult()
{
	for (int s : result) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

void BestNStlSort::PrintSortedData()
{
	for (int s : sorted_data) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

void BestNStlSort::SelectBestN()
{
	int selected_best = 0;
	std::sort(sorted_data.begin(), sorted_data.end(), CompareInt);
	size_t sorted_data_pos = sorted_data.size() - 1;
	

	while (selected_best != this->best_count) {
		result.push_back(sorted_data[sorted_data_pos]);
		selected_best++;
		sorted_data_pos--;
	}


}

inline bool BestNStlSort::CompareInt(const int& a, const int& b)
{
	return a < b;
}