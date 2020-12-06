#include "BestNstlNth.h"

BestNstlNth::BestNstlNth(size_t best_count)
{
	this->tag = "Best N std::nth";
	this->best_count = best_count;
}

void BestNstlNth::Execute()
{
	this->SelectBestN();
}

void BestNstlNth::InitData(unsigned int data_count, int min, int max)
{
	if (data_count < best_count)
		throw("Number of best elements could not be more than number of all elements");

	data.clear();
	sorted_data.clear();
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

void BestNstlNth::PrintData()
{
	for (int s : data) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

void BestNstlNth::PrintResult()
{
	for (int s : result) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

void BestNstlNth::PrintSortedData()
{
	for (int s : sorted_data) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

void BestNstlNth::SelectBestN()
{
	size_t selected_best = 0;
	std::nth_element(sorted_data.begin(), sorted_data.begin() + best_count, sorted_data.end(), std::greater<int>());

	for (; selected_best < this->best_count; ++selected_best) {
		result.push_back(sorted_data[selected_best]);
	}



}