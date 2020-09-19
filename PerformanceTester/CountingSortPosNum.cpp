#include "CountingSortPosNum.h"


CountingSortPosNum::CountingSortPosNum()
{
	this->tag = "CountingSortPosNum";
}

void CountingSortPosNum::Execute()
{
	unsigned int max = FindMax();
	
	std::vector<unsigned int> counts(max + 1);

	for (size_t i = 0; i < data.size(); ++i) {
		counts[data[i]] +=  1;
	}

	for (size_t i = 1; i < counts.size(); ++i) {
		counts[i] = counts[i] + counts[i - 1]; 
	}
	

	for (auto i = data.rbegin(); i != data.rend(); ++i) {
		sorted_data[counts[*i]] = *i;
		counts[*i] = counts[*i] - 1;
	}




}

void CountingSortPosNum::InitData(unsigned int data_count, unsigned int min, unsigned int max)
{
	data.clear();
	sorted_data.clear();

	std::random_device rd;
	std::mt19937 rne(rd());
	std::uniform_int_distribution<int> uid(min, max);

	sorted_data.resize(data_count + 1);

	for (unsigned int i = 0; i < data_count; ++i) {
		data.push_back(uid(rne));
	}


}

void CountingSortPosNum::PrintSortedData()
{
	for (size_t i = 0; i < sorted_data.size(); ++i) {
		std::cout << sorted_data[i] << " ";
	}

	std::cout << std::endl;
}

void CountingSortPosNum::PrintData()
{
	for (size_t i = 0; i < data.size(); ++i) {
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;

}

unsigned int CountingSortPosNum::FindMax()
{
	unsigned int max_val = data[0];
	for (size_t i = 1; i < data.size(); ++i) {
		if (data[i] > max_val) max_val = data[i];
	}

	return max_val;
}
