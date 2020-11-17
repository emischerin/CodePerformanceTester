#include "TestExecutor.h"

void TestExecutor::ExecImeasurement(IMeasurement& im)
{
	Measurement m;
	m.tag = im.tag;
	
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	im.Execute();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	m.seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	m.ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	m.h = std::chrono::duration_cast<std::chrono::hours>(end - start);
	m.ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

	

	results.push_back(m);
	

}

void TestExecutor::PrintResults()
{
	for (size_t i = 0; i < results.size(); ++i) {
		std::cout << results[i].tag
			<< ":" << "milliseconds=" <<
			results[i].ms.count() << std::endl;

		std::cout << results[i].tag
			<< ":" << "nanoseconds=" << 
			results[i].ns.count() << std::endl;

	}
}

void TestExecutor::SortResultsByTag()
{
	if(results.size() > 0) 
		std::sort(results.begin(), results.end(), SortByTag);
}

void TestExecutor::PrintMeanResults()
{
	CalculateMeanValues();

	for (auto i = average.begin(); i != average.end(); ++i) {
		std::cout << "Mean Result======" << i->first << ":" << i->second.ns.count() << " nanoseconds" << std::endl;
		std::cout << "Mean Result======" << i->first << ":" << i->second.ms.count() << " milliseconds" <<std::endl;
	}
}

void TestExecutor::CalculateMeanValues()
{
	std::unordered_map<std::string, size_t> counts_by_tags;

	CalculateMeasurementsCountByTag(counts_by_tags);

	for (size_t i = 0; i < results.size(); ++i) {
		average[results[i].tag].h += results[i].h;
		average[results[i].tag].ms += results[i].ms;
		average[results[i].tag].ns += results[i].ns;
		average[results[i].tag].seconds += results[i].seconds;
	}

	for (auto i = average.begin(); i != average.end(); ++i) {
		i->second.h = i->second.h / counts_by_tags[i->first];
		i->second.ms = i->second.ms / counts_by_tags[i->first];
		i->second.ns = i->second.ns / counts_by_tags[i->first];
		i->second.seconds = i->second.seconds / counts_by_tags[i->first];
	}
}

void TestExecutor::CalculateMeasurementsCountByTag(std::unordered_map<std::string, size_t>& counts_by_tag)
{
	for (size_t i = 0; i < results.size(); ++i) {
		counts_by_tag[results[i].tag]++;
	}

}

bool TestExecutor::SortByTag(const Measurement& first, const Measurement& second)
{
	 return first.tag < second.tag; 
}