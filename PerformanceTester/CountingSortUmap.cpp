#include "CountingSortUmap.h"


 void CountingSortUmap::Execute()
{
	std::unordered_map<int, unsigned int> counts; 

	for (size_t i = 0; i < data.size(); ++i) {
		counts[data[i]]++;
	}


	std::unordered_map<int, unsigned int>::iterator it = counts.begin();


	unsigned int less_count = it->second;
	

	//for(int i = )

	/*while (it != counts.end()) {

		
		it->second += less_count;
		less_count = it->second;
		it++;
	}*/
	
	
	 
	for (auto k = data.end(); k != data.begin(); --k) {
		
		sorted_data[counts[data[*k]]] = data[*k];
		counts[data[*k]] -= 1;
	}

	/*for (long long i = data.size(); i < 0; i--) {
		sorted_data[counts[data[i]]] = data[i];
		counts[data[i]] = counts[data[i]] - 1;

	}*/



	


}

 void CountingSortUmap::InitData(unsigned int data_count,int min,int max)
{
	data.clear();
	sorted_data.clear();

	std::random_device rd;
	std::mt19937 rne(rd());
	std::uniform_int_distribution<int> uid(min, max);
	
	sorted_data.resize(data_count);

	for (unsigned int i = 0; i < data_count; ++i) {
		data.push_back(uid(rne));
	}

	
}

 void CountingSortUmap::PrintData()
{
	for (size_t i = 0; i < data.size(); ++i) {
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;
		
}
