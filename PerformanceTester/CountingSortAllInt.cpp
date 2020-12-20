#include "CountingSortAllInt.h"

CountingSortAllInt::CountingSortAllInt()
{
	this->tag = "CountingSortAllInt";
	
}

void CountingSortAllInt::Execute()
{
	this->BestElements();
}

void CountingSortAllInt::InitData(unsigned int data_count, int min, int max)
{
	
	data.clear();
	sorted_data.clear();

	std::random_device rd;
	std::mt19937 rne(rd());
	std::uniform_int_distribution<int> uid(min, max);



	for (unsigned int i = 0; i < data_count; ++i) {
		data.push_back(uid(rne));
	}

	

}

void CountingSortAllInt::PrintData()
{
	for (int s : data) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

void CountingSortAllInt::PrintSortedData()
{
	for (int s : sorted_data) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

inline void CountingSortAllInt::SeparateNegativesAndPositives(const std::vector<int>& in,
	std::vector<int>& negatives, std::vector<int>& positives)
{
	for (int v : in) {
		if (v < 0) negatives.push_back(v);
		else positives.push_back(v);
	}
}

inline void CountingSortAllInt::SortPositiveElements(std::vector<int>& v, int elem_count)
{
	if (elem_count <= 0) return;
	if (v.size() < 1) return;

	

	std::vector<int>::iterator max = std::max_element(data.begin(), data.end());
	std::vector<int> counts((*max) + 1);
	



	for (size_t i = 0; i < v.size(); ++i) {
		counts[v[i]]++;
	}

	for (int i = 0; i != counts.size(); ++i) {
		if (counts[i] != 0) {
			while (counts[i] != 0) {
				sorted_data.push_back(i);
				counts[i]--;
			}

		}
	}
}

inline void CountingSortAllInt::SortNegativeElements(std::vector<int>& v, int elem_count)
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

	for (int i = counts.size() - 1; i > 0; --i) {
		if (counts[i] != 0) {
			while (counts[i] != 0) {
				sorted_data.push_back(-i);
				counts[i]--;
			}
				
		}
	}
}



inline void CountingSortAllInt::BestElements()
{
	std::vector<int> negatives;
	std::vector<int> positives;


	SeparateNegativesAndPositives(this->data, negatives, positives);

	size_t neg_size = negatives.size();
	size_t positive_size = positives.size();

	SortNegativeElements(negatives, neg_size);
	SortPositiveElements(positives, positive_size);
	
		


}