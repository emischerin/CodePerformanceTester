#include "Application.h"

void Application::RunAllTests(size_t tests_num,size_t data_count)
{

    for (size_t i = 0; i != tests_num; ++i) {
        
     cs_neg_num.InitData(data_count, -1100, -100);
     cs_pos_num.InitData(data_count, 100, 1100);
     qs.InitData(data_count, -1100, 1100);
     //bs.InitData(data_count, -1100, 1100);
     ms.InitData(data_count, -1100, 1100);
     sms.InitData(data_count, -1100, 1100);
     oms.InitData(data_count, -1100, 1100);
       
        //snn.PrintData();
        te.ExecImeasurement(cs_neg_num);
        te.ExecImeasurement(cs_pos_num);
        te.ExecImeasurement(qs);
        //te.ExecImeasurement(bs);
        te.ExecImeasurement(ms);
        te.ExecImeasurement(sms);
        te.ExecImeasurement(oms);
    }



    te.SortResultsByTag();
    te.PrintResults();
}


void Application::RunCountingSortNegNumTest()
{
    CountingSortNegNum csnn;

    csnn.InitData(10, -100, -1);
    csnn.PrintData();
    csnn.Execute();
    csnn.PrintSortedData();
}

void Application::RunCountingSortPosNumTest()
{
    CountingSortPosNum cspn;

    cspn.InitData(10, 100, 200);
    cspn.Execute();
    cspn.PrintSortedData();
}

void Application::RunQuickSortTest()
{
    QuickSort qs;

    qs.InitData(10, -1000, 1000);
    qs.PrintData();
    qs.Execute();
    qs.PrintSortedData();
}

void Application::RunBubbleSortTest()
{
    BubbleSort bs;

    bs.InitData(10, -100, 100);
    bs.PrintData();
    bs.Execute();
    bs.PrintSortedData();
}

void Application::RunMergeSortTest()
{
    MergeSort ms;

    ms.InitData(10, -100, 100);
    ms.PrintData();
    ms.Execute();
    ms.PrintSortedData();
}

void Application::RunSedgewickMergeSortTest()
{
    SedgewickMergeSort smss;

    smss.InitData(10, -100, 100);
    smss.PrintData();
    smss.Execute();
    smss.PrintSortedData();
}

void Application::RunOptimizedMergeSortTest()
{
    OptimizedMergeSort oms;
    oms.InitData(10, 100, 1000);
    oms.PrintData();
    oms.Execute();
    oms.PrintSortedData();
}

void Application::RunBestNElementsTest()
{
    BestNElements b_elements(4);

    b_elements.InitData(10,0,20);
    b_elements.PrintData();
    b_elements.Execute();
    b_elements.PrintResult();
}

void Application::RunBestNAllIntTest()
{
    BestNAllInt b_allint(5);

    b_allint.InitData(1000, -1000, 1000);
    b_allint.PrintData();
    b_allint.Execute();
    b_allint.PrintResult();
}

void Application::RunBestNStlSortTest()
{
    BestNStlSort b_stl_sort(4);
    b_stl_sort.InitData(15, -15, 15);
    b_stl_sort.PrintData();
    b_stl_sort.Execute();
    b_stl_sort.PrintSortedData();
    b_stl_sort.PrintResult();
    
}