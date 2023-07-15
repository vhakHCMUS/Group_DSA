#include "SortAlg.h"
#include <iostream>

using namespace std;

void selectionSort(int* array, int size, int &count_assign, int& count_compare)
{
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        count_compare++;
        for(int j=i+1;j<size;j++)
        {
            count_compare++;
            if(array[j]<array[min])
            {
                min=j;
                count_assign++;
            }
        }
        swap(array[min],array[i]);
        count_assign+=3;
    }
}

//write selectionSort and count the number of assignments and comparisons
void insertionSort(int* array, int size, int &count_assign, int& count_compare)
{
    for(int i=1;i<size;i++)
    {
        count_compare++;
        int key=array[i];
        int j=i-1;
        count_assign+=2;
        while(j>=0&&array[j]>key)
        {
            array[j+1]=array[j];
            j--;
            count_assign+=2;
            count_compare++;
        }
        array[j+1]=key;
        count_assign++;
    }
}

//write bubbleSort and count the number of assignments and comparisons
void bubbleSort(int* array, int size, int &count_assign, int& count_compare)
{
    for(int i=0;i<size-1;i++)
    {
        count_compare++;
        for(int j=0;j<size-i-1;j++)
        {
            count_compare++;
            if(array[j]>array[j+1])
            {
                swap(array[j],array[j+1]);
                count_assign+=3;
            }
        }
    }
}