#include "BElementsCounts.h"

BElementsCounts::BElementsCounts(size_t elements_count)
{
	this->tag = "Best N Elements";
	this->elements_count = elements_count;
}

void BElementsCounts::Execute()
{
	this->BestNElements(3);
}

void BElementsCounts::InitData(unsigned int data_count, int min, int max)
{
	if (data_count == 0) return;

	int val = 0;
	data.clear();
	result.clear();

	data.resize(data_count);
	result.resize(this->elements_count);

	std::random_device rd;
	std::mt19937 rne(rd());
	std::uniform_int_distribution<int> uid(min, max);




	for (size_t i = 0; i < data_count; ++i) {
		val = uid(rne);
		data[i] = val;
		
	}
}

void BElementsCounts::PrintData()
{
	for (int i : data) { std::cout << i << " "; }
	std::cout << std::endl;
}

void BElementsCounts::PrintResult()
{
	for (int i : result) { std::cout << i << " "; }
	std::cout << std::endl;
}

void BElementsCounts::BestNElements(size_t elem_count)
{
	if (elem_count > data.size()) throw "Count of elements < data size";

	if()

}