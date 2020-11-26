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
#include "BestNElements.h"
#include "BestNAllInt.h"
#include "BestNStlSort.h"

class Application
{
public:
	void RunAllTests(size_t tests_num,size_t data_count);

    void RunCountingSortNegNumTest();

    void RunCountingSortPosNumTest();

    void RunQuickSortTest();

    void RunBubbleSortTest();

    void RunMergeSortTest();

    void RunSedgewickMergeSortTest();

    void RunOptimizedMergeSortTest();

    void RunBestNElementsTest();

    void RunBestNAllIntTest();

    void RunBestNStlSortTest();

private:
    TestExecutor te;
    CountingSortNegNum cs_neg_num;
    CountingSortPosNum cs_pos_num;
    QuickSort qs;
    BubbleSort bs;
    MergeSort ms;
    SedgewickMergeSort sms;
    OptimizedMergeSort oms;
};

