#include "BestNAllInt.h"

BestNAllInt::BestNAllInt(size_t best_count)
{
	this->tag = "BestNElements(CountingSortBased)";
	this->best_count = best_count;
}

void BestNAllInt::Execute()
{
	this->BestElements();
}

void BestNAllInt::InitData(unsigned int data_count,int min,int max)
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

void BestNAllInt::PrintData()
{
	for (int s : data) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

void BestNAllInt::PrintResult()
{
	for (int s : result) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

inline void BestNAllInt::SeparateNegativesAndPositives(const std::vector<int>& in,
	std::vector<int>& negatives, std::vector<int>& positives)
{
	for (int v : in) {
		if (v < 0) negatives.push_back(v);
		else positives.push_back(v);
	}
}

inline void BestNAllInt::SelectBestPositiveElements(std::vector<int>& v,int elem_count)
{
	if (elem_count <= 0) return;
	if (v.size() < 1) return;

	size_t best_counter = 0;

	std::vector<int>::iterator max = std::max_element(data.begin(), data.end());
	std::vector<int> counts((*max) + 1);
	int counts_pos = counts.size() - 1;



	for (size_t i = 0; i < v.size(); ++i) {
		counts[v[i]]++;
	}

	while ((best_counter != elem_count) && (counts_pos > 0)) {
		if (counts[counts_pos] != 0) {
			while ((counts[counts_pos] != 0) && (best_counter != elem_count)) {
				result.push_back(counts_pos);
				counts[counts_pos]--;
				best_counter++;
			}
		}
		counts_pos--;
	}
}

inline void BestNAllInt::SelectBestNegativeElements(std::vector<int>& v,int elem_count)
{
	if (elem_count <= 0) return;
	if (v.size() < 1) return;


	size_t best_counter = 0;

	std::vector<int>::iterator min = std::min_element(data.begin(), data.end());
	
	int max = -(*min);

	std::vector<int> counts(max + 1);
	int counts_pos = 0;



	for (size_t i = 0; i < v.size(); ++i) {
		v[i] = -v[i]; // we have to inverse signs, because it's impossible to store at e.g. v[-3]
		counts[v[i]]++;
	}

	while (best_counter != elem_count) {
		if (counts[counts_pos] != 0) {
			while ((counts[counts_pos] != 0) && (best_counter != elem_count)) {
				result.push_back(-counts_pos); // placing into vecor<int> and restoring the sign
				counts[counts_pos]--;
				best_counter++;
			}
		}
		counts_pos++;
	}
}



void BestNAllInt::BestElements()
{
	std::vector<int> negatives;
	std::vector<int> positives;
	

	SeparateNegativesAndPositives(data, negatives, positives);

	size_t neg_size = negatives.size();
	size_t positive_size = positives.size();
	


	if (positive_size >= this->best_count) {
		SelectBestPositiveElements(positives, this->best_count);
		return;
	}
	else if (positive_size < this->best_count) {
		SelectBestPositiveElements(positives, this->best_count);
		SelectBestNegativeElements(negatives, this->best_count - positive_size);

	}


}