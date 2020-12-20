#include "Application.h"

void Application::RunAllSortingTests(size_t tests_num,size_t data_count)
{

    for (size_t i = 0; i != tests_num; ++i) {
        
     cs_neg_num.InitData(data_count, -1100, -100);
     cs_pos_num.InitData(data_count, 100, 1100);
     qs.InitData(data_count, -1100, 1100);
     //bs.InitData(data_count, -1100, 1100);
     ms.InitData(data_count, -1100, 1100);
     sms.InitData(data_count, -1100, 1100);
     oms.InitData(data_count, -1100, 1100);
     cs_all_int.InitData(data_count, -5000, 5000);
       
        //snn.PrintData();
        te.ExecImeasurement(cs_neg_num);
        te.ExecImeasurement(cs_pos_num);
        te.ExecImeasurement(qs);
        //te.ExecImeasurement(bs);
        te.ExecImeasurement(ms);
        te.ExecImeasurement(sms);
        te.ExecImeasurement(oms);
        te.ExecImeasurement(cs_all_int);
    }



  
    
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

void Application::RunCountingSortAllIntTest()
{
    CountingSortAllInt cs_all_int;

    cs_all_int.InitData(10, -100, 100);
    cs_all_int.PrintData();
    cs_all_int.Execute();
    cs_all_int.PrintSortedData();
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

void Application::RunBestNRandSelectTest()
{
    BestNRandSelect b_rand_select(4);

    b_rand_select.InitData(15, -15, 15);
    b_rand_select.PrintData();
    b_rand_select.Execute();
    b_rand_select.PrintResult();



}

void Application::RunBestNstdNthTest()
{
    BestNstlNth stlnth(4);

    stlnth.InitData(15, -15, 15);
    stlnth.PrintData();
    stlnth.Execute();
    stlnth.PrintSortedData();
    stlnth.PrintResult();

}

void Application::RunAllBestNElementsTests(size_t tests_count, size_t data_count,size_t best_count)
{
    BestNElements b_elements(best_count);
    BestNAllInt b_allint(best_count);
    BestNStlSort b_stl_sort(best_count);
    BestNRandSelect b_rand_select(best_count);
    BestNstlNth b_stl_nth(best_count);


    for (size_t i = 0; i < tests_count; ++i) {
        b_elements.InitData(data_count, 0, 10000000);
        b_allint.InitData(data_count, -10000000, 10000000);
        b_stl_sort.InitData(data_count, -10000000, 10000000);
        b_rand_select.InitData(data_count, -10000000, 10000000);
        b_stl_nth.InitData(data_count, -10000000, 10000000);


        te.ExecImeasurement(b_elements);
        te.ExecImeasurement(b_stl_sort);
        te.ExecImeasurement(b_rand_select);
        te.ExecImeasurement(b_stl_nth);
        te.ExecImeasurement(b_allint);
    }

  
   

}

void Application::PrintResultsToConsole()
{
    te.SortResultsByTag();
    te.PrintResults();
}