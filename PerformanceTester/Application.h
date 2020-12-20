#pragma once
#include <iostream>
#include "TestExecutor.h"
#include "CountingSortPosNum.h"
#include "CountingSortNegNum.h"
#include "IMeasurement.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "SedgewickMergeSort.h"
#include "OptimizedMergeSort.h"
#include "CountingSortAllInt.h"
#include "BestNElements.h"
#include "BestNAllInt.h"
#include "BestNStlSort.h"
#include "BestNRandSelect.h"
#include "BestNstlNth.h"

class Application
{
public:
	void RunAllSortingTests(size_t tests_num,size_t data_count);

    void RunCountingSortNegNumTest();

    void RunCountingSortPosNumTest();

    void RunCountingSortAllIntTest();

    void RunQuickSortTest();

    void RunBubbleSortTest();

    void RunMergeSortTest();

    void RunSedgewickMergeSortTest();

    void RunOptimizedMergeSortTest();

    void RunBestNElementsTest();

    void RunBestNAllIntTest();

    void RunBestNStlSortTest();

    void RunBestNRandSelectTest();

    void RunBestNstdNthTest();

    void RunAllBestNElementsTests(size_t tests_count,size_t data_count,size_t best_count);

    void PrintResultsToConsole();

private:

    
    TestExecutor te;

    /* SORTING*/
    CountingSortNegNum cs_neg_num;
    CountingSortPosNum cs_pos_num;
    CountingSortAllInt cs_all_int;
    QuickSort qs;
    BubbleSort bs;
    MergeSort ms;
    SedgewickMergeSort sms;
    OptimizedMergeSort oms;
    
    /* SELECTING LARGEST OR SMALLEST ELEMENTS*/

    

};

