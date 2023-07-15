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

//write heapSort and count the number of assignments and comparisons
void heapify(int* array, int size, int i, int &count_assign, int& count_compare)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    count_compare+=2;
    if(l<size&&array[l]>array[largest])
    {
        largest=l;
        count_assign++;
    }
    count_compare+=2;
    if(r<size&&array[r]>array[largest])
    {
        largest=r;
        count_assign++;
    }
    count_compare++;
    if(largest!=i)
    {
        swap(array[i],array[largest]);
        count_assign+=3;
        heapify(array,size,largest,count_assign,count_compare);
    }
}
void heapSort(int* array, int size, int &count_assign, int& count_compare)
{
    for(int i=size/2-1;i>=0;i--)
    {
        count_compare++;
        heapify(array,size,i,count_assign,count_compare);
    }
    for(int i=size-1;i>=0;i--)
    {
        count_compare++;
        swap(array[0],array[i]);
        count_assign+=3;
        heapify(array,i,0,count_assign,count_compare);
    }
}
//write countingSort and count the number of assignments and comparisons
void countingSort(int* array, int size, int &count_assign, int& count_compare)
{
    int max=array[0];
    for(int i=1;i<size;i++)
    {
        count_compare+=2;
        if(array[i]>max)
        {
            max=array[i];
            count_assign++;
        }
    }
    int* count=new int[max+1];
    for(int i=0;i<max+1;i++)
    {
        count_compare++;
        count[i]=0;
        count_assign++;
    }
    for(int i=0;i<size;i++)
    {
        count[array[i]]++;
        count_assign++;
    }
    int index=0;
    for(int i=0;i<max+1;i++)
    {
        count_compare++;
        while(count[i]>0)
        {
            array[index]=i;
            index++;
            count[i]--;
            count_assign+=2;
        }
    }
    delete[] count;
}

//write radixSort and count the number of assignments and comparisons
void radixSort(int* array, int size, int &count_assign, int& count_compare)
{
    int max=array[0];
    for(int i=1;i<size;i++)
    {
        count_compare++;
        if(array[i]>max)
        {
            max=array[i];
            count_assign++;
        }
    }
    for(int exp=1;max/exp>0;exp*=10)
    {
        int* output=new int[size];
        int count[10]={0};
        count_assign++;
        count_compare++;
        for(int i=0;i<size;i++)
        {
            count_compare++;
            count[(array[i]/exp)%10]++;
            count_assign++;
        }
        for(int i=1;i<10;i++)
        {
            count_compare++;
            count[i]+=count[i-1];
            count_assign++;
        }
        for(int i=size-1;i>=0;i--)
        {
            count_compare++;
            output[count[(array[i]/exp)%10]-1]=array[i];
            count[(array[i]/exp)%10]--;
            count_assign+=2;
        }
        for(int i=0;i<size;i++)
        {
            count_compare++;
            array[i]=output[i];
            count_assign++;
        }
        delete[] output;
    }
}

//write quickSort and count the number of assignments and comparisons
int partition(int* array, int low, int high, int &count_assign, int& count_compare)
{
    int pivot=array[high];
    int i=low-1;
    count_assign+=2;
    for(int j=low;j<=high-1;j++)
    {
        count_compare+=2;
        if(array[j]<=pivot)
        {
            i++;
            swap(array[i],array[j]);
            count_assign+=3;
        }
    }
    swap(array[i+1],array[high]);
    count_assign+=3;
    return i+1;
}
void quickSort(int* array, int low, int high, int &count_assign, int& count_compare)
{
    if(low<high)
    {
        count_compare++;
        int pi=partition(array,low,high,count_assign,count_compare);
        quickSort(array,low,pi-1,count_assign,count_compare);
        quickSort(array,pi+1,high,count_assign,count_compare);
    }
}