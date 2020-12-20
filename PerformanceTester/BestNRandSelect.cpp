#include "BestNRandSelect.h"

BestNRandSelect::BestNRandSelect(int best_count)
{
	this->tag = "Best N Randomized Select";
	this->best_count = best_count;
}

void BestNRandSelect::Execute()
{
	this->SelectBestN();
}

void BestNRandSelect::InitData(int data_count, int min, int max)
{
	if (data_count < best_count)
		throw("Number of best elements could not be more than number of all elements");

	data.clear();
	result.clear();

	int random_int;
	std::random_device rd;
	std::mt19937 rne(rd());
	std::uniform_int_distribution<int> uid(min, max);



	for (int i = 0; i < data_count; ++i) {
		random_int = uid(rne);
		data.push_back(random_int);
		
	}
}

void BestNRandSelect::PrintData()
{
	for (int s : data) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

void BestNRandSelect::PrintResult()
{
	for (int s : result) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}


int BestNRandSelect::RandomizedPartition(int low, int high)
{
	int random;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> urd(low, high);

	random = urd(mt);

	std::swap(data[random], data[high]);

	return Partition(low, high);
}

int BestNRandSelect::Partition(int low, int high)
{
	int pivot = low;

	for (int i = low; i < high; ++i) {
		if (data[i] >= data[high]) {
			std::swap(data[i], data[pivot]);
			pivot++;

		}

	}

	std::swap(data[pivot], data[high]);

	return pivot;
}

int BestNRandSelect::RandomizedSelect(int low, int high, int search_index)
{
	if (low == high) return data[low];

	int x = RandomizedPartition(low, high);
	int b = x - low + 1;

	if (search_index == b) {
		return data[x];
	}
	else if (search_index < b) {
		return RandomizedSelect(low, x - 1, search_index);
	}
	else {
		return RandomizedSelect(x + 1, high, search_index - b);
	}
}

void BestNRandSelect::SelectBestN()
{
	int best_i = 1;
	int bestN;

	while (best_i <= best_count) {
		bestN = RandomizedSelect(0, data.size() - 1, best_i);
		result.push_back(bestN);
		best_i++;
	}
	

}