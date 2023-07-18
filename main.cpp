#include <iostream>
#include "DataGenerator.h"
#include "SortAlg.h"

using namespace std;


int main()
{
    for (int dataType = 0; dataType < 4 ; dataType++)
    {
        /* Data Size Examine the selected sorting algorithms on data of the following sizes: 10,000, 30,000, 50,000, 100,000, 300,000, and 500,000 elements.*/
        for (int dataSize = 10000; dataSize <= 50000; dataSize += 20000)
        {
            int* array = new int[dataSize];
            int count_assign = 0;
            int count_compare = 0;
            float Time = 0;
            for (int sortType = 1; sortType <= 10; sortType++)
            {
                GenerateData(array, dataSize, dataType);
                SortChoosing(array, dataSize, sortType, count_assign, count_compare, Time);
                /*
                write with this format 
                Data type : Nearly Sorted
                Data size : 10000
                Sort type : Bubble sort
                Number of assignment : 100
                Number of comparison : 100
                Time : 0.0001
                */
                cout<<"Data type : ";
                switch (dataType)
                {
                case 0:
                    cout<<"Random"<<endl;
                    break;
                case 1:
                    cout<<"Sorted"<<endl;
                    break;
                case 2:
                    cout<<"Reverse"<<endl;
                    break;
                case 3:
                    cout<<"Nearly Sorted"<<endl;
                    break;
                }
                cout<<"Data size : "<<dataSize<<endl;
                cout<<"Sort type : ";
                switch (sortType)
                {
                case 1:
                    cout<<"Selection sort"<<endl;
                    break;
                case 2:
                    cout<<"Insertion sort"<<endl;
                    break;
                case 3:
                    cout<<"Bubble sort"<<endl;
                    break;
                case 4:
                    cout<<"Heap sort"<<endl;
                    break;
                case 5:
                    cout<<"Counting sort"<<endl;
                    break;
                case 6:
                    cout<<"Radix sort"<<endl;
                    break;
                case 7:
                    cout<<"Quick sort"<<endl;
                    break;
                case 8:
                    cout<<"Merge sort"<<endl;
                    break;
                case 9:
                    cout<<"Shell sort"<<endl;
                    break;
                case 10:
                    cout<<"Shaker sort"<<endl;
                    break;
                }
                cout<<"Number of assignment : "<<count_assign<<endl;
                cout<<"Number of comparison : "<<count_compare<<endl;
                cout<<"Time : "<<Time<<endl;
                cout<<"---------------------------------"<<endl;
            }
            delete[] array;
        }
        for (int dataSize = 100000; dataSize <= 500000; dataSize += 200000)
                {
            int* array = new int[dataSize];
            int count_assign = 0;
            int count_compare = 0;
            float Time = 0;
            for (int sortType = 1; sortType <= 10; sortType++)
            {
                GenerateData(array, dataSize, dataType);
                SortChoosing(array, dataSize, sortType, count_assign, count_compare, Time);
               
            }
            delete[] array;
        }
    }

}