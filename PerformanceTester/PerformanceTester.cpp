// PerformanceTester.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "TestExecutor.h"
#include "CountingSortPosNum.h"
#include "CountingSortNegNum.h"
#include "IMeasurement.h"
#include "QuickSort.h"
#include "BubbleSort.h"

int main()
{
    TestExecutor te;
    CountingSortNegNum cs_neg_num;
    CountingSortPosNum cs_pos_num;
    QuickSort qs;
    BubbleSort bs;

  

   

    for (int i = 0; i < 5; ++i) {
        try {
            cs_neg_num.InitData(50, -1100, -100);
            cs_pos_num.InitData(50, 100, 1100);
            qs.InitData(50,-1100,1100);
            bs.InitData(50, -1100, 1100);
        }
        catch (std::string& exception) {
            std::cout << exception << std::endl;
        }
        //snn.PrintData();
        te.ExecImeasurement(cs_neg_num);
        te.ExecImeasurement(cs_pos_num);
        te.ExecImeasurement(qs);
        te.ExecImeasurement(bs);
    }
    

   

    te.PrintResults();
    

    return 0;


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
