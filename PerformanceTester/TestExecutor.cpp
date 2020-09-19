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