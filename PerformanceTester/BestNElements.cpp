#include "BestNElements.h"

BestNElements::BestNElements(size_t best_count)
{
	this->tag = "BestNElements(Positive Only)";
	this->best_count = best_count;
}

void BestNElements::Execute()
{
	this->BestElements();
}

void BestNElements::InitData(unsigned int data_count, unsigned int min, unsigned int max)
{
	if (data_count < best_count) 
		throw("Number of best elements could not be more than number of all elements");

	data.clear();
	result.clear();

	std::random_device rd;
	std::mt19937 rne(rd());
	std::uniform_int_distribution<int> uid(min, max);

	

	for (unsigned int i = 0; i < data_count; ++i) {
		data.push_back(uid(rne));
	}


}

void BestNElements::PrintData()
{
	for (size_t s : data) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

void BestNElements::PrintResult()
{
	for (size_t s : result) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

void BestNElements::BestElements()
{
	size_t best_counter = 0;
	std::vector<size_t>::iterator max = std::max_element(data.begin(), data.end());
	std::vector<size_t> counts(*max + 1);
	size_t counts_pos = counts.size() - 1;

	for (size_t i = 0; i < data.size(); ++i) {
		counts[data[i]]++;
	}

	while (best_counter != best_count) {
		if (counts[counts_pos] != 0) {
			while ((counts[counts_pos] != 0) && (best_counter != best_count)) {
				result.push_back(counts_pos);
				counts[counts_pos]--;
				best_counter++;
			}
		}
		counts_pos--;
	}



}