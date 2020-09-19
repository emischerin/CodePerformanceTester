#include "CountingSortNegNum.h"


CountingSortNegNum::CountingSortNegNum()
{
	this->tag = "CountingSortNegNum";
}

bool CountingSortNegNum::Validate() 
{
	if (data.size() == 0 || data.empty()) return false;

	for (size_t i = 0; i < data.size(); ++i) {
		if (data[i] > 0) return false;
	}

	return true;
}

void CountingSortNegNum::Execute()
{
	if (!Validate()) return;

	InverseSigns(data);

	int max = FindMax();

	

	std::vector<unsigned int> counts(max + 1);

	for (size_t i = 0; i < data.size(); ++i) {
		counts[data[i]] += 1;
	}

	for (size_t i = 1; i < counts.size(); ++i) {
		counts[i] = counts[i] + counts[i - 1];
	}


	for (auto i = data.rbegin(); i != data.rend(); ++i) {
		sorted_data[counts[*i]] = *i;
		counts[*i] = counts[*i] - 1;
	}

	InverseSigns(sorted_data);



}

void CountingSortNegNum::InitData(unsigned int data_count,int min,int max)
{
	if (max > 0) throw "Max > 0 exception!";

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

void CountingSortNegNum::PrintSortedData()
{
	for (size_t i = 0; i < sorted_data.size(); ++i) {
		std::cout << sorted_data[i] << " ";
	}

	std::cout << std::endl;
}

void CountingSortNegNum::PrintData()
{
	for (size_t i = 0; i < data.size(); ++i) {
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;

}

unsigned int CountingSortNegNum::FindMax()
{
	int max_val = data[0];
	for (size_t i = 1; i < data.size(); ++i) {
		if (data[i] > max_val) max_val = data[i];
	}

	return max_val;
}

void CountingSortNegNum::InverseSigns(std::vector<int>& v)
{
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] = -v[i];
	}
}