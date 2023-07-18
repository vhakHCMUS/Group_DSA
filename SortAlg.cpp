#include "SortAlg.h"
#include <iostream>
#include <time.h>

using namespace std;

void selectionSort(int* array, int size, long long &count_assign, long long& count_compare, float& Time)
{
    //apply clock to count the time
    clock_t start, end, total;
    start = clock();
	count_assign=0;
	count_compare=0;
	count_assign++;
    for(int i=0; count_compare++,i<size-1;count_assign++,i++)
    {
        int min=i;
        count_assign+=2;
        for(int j=i+1;count_compare++,j<size;count_assign++,j++)
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
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

//write selectionSort and count the number of assignments and comparisons
void insertionSort(int* array, int size, long long&count_assign, long long& count_compare, float& Time)
{
	count_assign=0;
	count_compare=0;
    clock_t start, end, total;
    start = clock();
	count_assign++;
    for(int i=1;count_compare++,i<size;count_assign++,i++)
    {
        int key=array[i];
        int j=i-1;
        count_assign+=2;
        while((count_compare++ &&j>=0)&&(count_compare++&&array[j]>key))
        {
            array[j+1]=array[j];
            j--;
            count_assign+=2;
        }
        array[j+1]=key;
        count_assign++;
    }
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

//write bubbleSort and count the number of assignments and comparisons
void bubbleSort(int* array, int size, long long &count_assign, long long& count_compare, float& Time)
{
	count_assign=0;
	count_compare=0;
	count_assign++;
    clock_t start, end, total;
    start = clock();
    for(int i=0;count_compare++,i<size-1;count_assign++,i++)
    {
        count_assign++;
        for(int j=0;count_compare++,j<size-i-1;count_assign++,j++)
        {
            count_compare++;
            if(array[j]>array[j+1])
            {
                swap(array[j],array[j+1]);
                count_assign+=3;
            }
        }
    }
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

//write heapSort and count the number of assignments and comparisons
void heapify(int* array, int size, int i, long long& count_assign, long long& count_compare)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    count_assign += 3;
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
        count_assign+=4;
        heapify(array,size,largest,count_assign,count_compare);
    }
}
void heapSort(int* array, int size, long long & count_assign, long long& count_compare, float& Time)
{
	count_assign=0;
	count_compare=0;
	count_assign++;
    clock_t start, end, total;
    start = clock();
    for(int i=size/2-1;count_compare++,i>=0;count_assign++,i--)
    {
        heapify(array,size,i,count_assign,count_compare);
    }
    for(int i=size-1;i>=0;i--)
    {
        count_compare++;
        swap(array[0],array[i]);
        count_assign+=3;
        heapify(array,i,0,count_assign,count_compare);
    }
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}
//write countingSort and count the number of assignments and comparisons
void countingSort(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
	count_assign=0;
	count_compare=0;
    int max=array[0];
    count_assign+=2;
    clock_t start, end, total;
    start = clock();
    for(int i=1;count_compare++,i<size;count_assign++,i++)
    {
        count_compare++;
        if(array[i]>max)
        {
            max=array[i];
            count_assign++;
        }
    }
    int* count=new int[max+1];
    count_assign+=2;
    for(int i=0;count_compare++,i<max+1;count_assign++,i++)
    {
        count[i]=0;
        count_assign++;
    }
    count_assign++;
    for(int i=0;count_compare++,i<size;count_assign++,i++)
    {
        count[array[i]]++;
        count_assign++;
    }
    int index=0;
    count_assign+=2;
    for(int i=0;count_compare++,i<max+1;count_assign++,i++)
    {
        while(count_compare++&&count[i]>0)
        {
            array[index]=i;
            index++;
            count[i]--;
            count_assign+=3;
        }
    }
    delete[] count;
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

//write radixSort and count the number of assignments and comparisons
void radixSort(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
	count_assign=0;
	count_compare=0;
    clock_t start, end, total;
    start = clock();
    int max=array[0];
    count_assign+=2;
    for(int i=1;count_compare++,i<size;count_assign++,i++)
    {
        if(count_compare++ && array[i]>max)
        {
            max=array[i];
            count_assign++;
        }
    }
    count_assign++;
    for(int exp=1;count_compare++,max/exp>0;count_assign++,exp*=10)
    {
        int* output=new int[size];
        int count[10]={0};
        count_assign+=3;
        for(int i=0;count_compare++,i<size;count_assign++,i++)
        {
            count[(array[i]/exp)%10]++;
            count_assign++;
        }
        count_assign++;
        for(int i=1;count_compare++,i<10;count_assign++,i++)
        {
            count[i]+=count[i-1];
            count_assign++;
        }
        count_assign++;
        for(int i=size-1;count_compare++,i>=0;count_assign++,i--)
        {
            output[count[(array[i]/exp)%10]-1]=array[i];
            count[(array[i]/exp)%10]--;
            count_assign+=2;
        }
        count_assign++;
        for(int i=0;count_compare++,i<size;count_assign++,i++)
        {
            array[i]=output[i];
            count_assign++;
        }
        delete[] output;
    }
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

//write quickSort and count the number of assignments and comparisons
int partition(int* array, int low, int high, long long& count_assign, long long& count_compare)
{
    int pivot=array[high];
    int i=low-1;
    count_assign+=3;
    for(int j=low;count_compare++,j<=high-1;count_assign++,j++)
    {
        if(count_compare++ && array[j]<=pivot)
        {
            i++;
            swap(array[i],array[j]);
            count_assign+=4;
        }
    }
    swap(array[i+1],array[high]);
    count_assign+=3;
    return i+1;
}
void quickSort(int* array, int low, int high, long long& count_assign, long long& count_compare)
{
    if(count_compare++ && low<high)
    {
        int pi=partition(array,low,high,count_assign,count_compare);
        count_assign+=3;
        quickSort(array,low,pi-1,count_assign,count_compare);
        quickSort(array,pi+1,high,count_assign,count_compare);
    }
}
void qSortCount(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
    clock_t start, end, total;
    int low = 0;
    int high = size-1;
    count_assign=0;
    
    start = clock();
    quickSort(array,low, high, count_assign, count_compare);
    end = clock();
    Time = (float)total/CLOCKS_PER_SEC;

}
//mergeSort and count the number of assignments and comparisons
void merge(int* array, int l, int m, int r, long long& count_assign, long long& count_compare)
{
    int n1=m-l+1;
    int n2=r-m;
    int* L=new int[n1];
    int* R=new int[n2];
    count_assign+=5;
    for(int i=0;count_compare++,i<n1;count_assign++,i++)
    {
        L[i]=array[l+i];
        count_assign++;
    }
    count_assign++;
    for(int i=0;count_compare++,i<n2;count_assign++,i++)
    {
        R[i]=array[m+1+i];
        count_assign++;
    }
    int i=0;
    int j=0;
    int k=l;
    count_assign+=3;
    while((count_compare++&&i<n1)&&(count_compare++&&j<n2))
    {
        count_compare++;
        if(L[i]<=R[j])
        {
            array[k]=L[i];
            i++;
            count_assign+=2;
        }
        else
        {
            array[k]=R[j];
            j++;
            count_assign+=2;
        }
        k++;
        count_assign++;
    }
    while(count_compare++ && i<n1)
    {
        array[k]=L[i];
        i++;
        k++;
        count_assign+=3;
    }
    while(count_compare++ && j<n2)
    {
        array[k]=R[j];
        j++;
        k++;
        count_assign+=3;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int* array, int l, int r, long long& count_assign, long long& count_compare) {
	count_assign=0;
	count_compare=0;
    if (count_compare++ && l < r) {
    count_assign+=3;
    int m = l + (r - l) / 2;
    mergeSort(array, l, m,count_assign,count_compare);
    mergeSort(array, m + 1, r,count_assign,count_compare);
    merge(array, l, m, r,count_assign,count_compare);
  }

}

void mergeSortCount(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
    clock_t start, end, total;
    int l = 0;
    int r = size-1;
    start = clock();
    mergeSort(array,l,r,count_assign,count_compare);
    end = clock();
    Time = (float)total/CLOCKS_PER_SEC;
}
//write shellSort and count the number of assignments and comparisons
void shellSort(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
	count_assign=0;
	count_compare=0;
    clock_t start, end, total;
    start = clock();
	count_assign++;
    for(int gap=size/2;count_compare++,gap>0;count_assign++,gap/=2)
    {
        for(int i=gap;count_compare++,i<size;count_assign++,i++)
        {
            int temp=array[i];
            int j;
            count_assign+=3;
            for(j=i;(count_compare++&&j>=gap)&&(count_compare++&&array[j-gap]>temp);count_assign++,j-=gap)
            {
                array[j]=array[j-gap];
                count_assign++;
            }
            array[j]=temp;
            count_assign++;
        }
    }
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

//write shakerSort and count the number of assignments and comparisons
void shakerSort(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
	count_assign=0;
	count_compare=0;
    clock_t start, end, total;
    start = clock();
    bool swapped=true;
    count_assign += 3;
    int start_index=0;
    int end_index=size-1;
    while(count_compare++ && swapped)
    {
        swapped=false;
        count_assign++;
        for(int i=start_index;count_compare++,i<end_index;count_assign++,i++)
        {
            if(count_compare++ && array[i]>array[i+1])
            {
                swap(array[i],array[i+1]);
                swapped=true;
                count_assign+=3;
            }
        }
        end_index--;
        count_assign++;
        for(int i=end_index-1;count_compare++,i>=start_index;count_assign++,i--)
        {
            if(count_compare++ && array[i]>array[i+1])
            {
                swap(array[i],array[i+1]);
                swapped=true;
                count_assign+=3;
            }
        }
        start_index++;
        count_assign++;
    }
    end = clock();
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

void SortChoosing(int* array, int size, int sortType, long long& count_assign, long long& count_compare, float &Time)
{
    switch (sortType)
    {
    case 1:
        selectionSort(array, size, count_assign, count_compare, Time);
        break;
    case 2:
        insertionSort(array, size, count_assign, count_compare, Time);
        break;
    case 3: 
        bubbleSort(array, size, count_assign, count_compare, Time);
        break;
    case 4:
        heapSort(array, size, count_assign, count_compare, Time);
        break;
    case 5: 
        countingSort(array, size, count_assign, count_compare, Time);
        break;
    case 6:
        radixSort(array, size, count_assign, count_compare, Time);
        break;
    case 7:
        qSortCount(array, size, count_assign, count_compare, Time);
        break;
    case 8:
        mergeSortCount(array, size, count_assign, count_compare, Time);
        break;
    case 9:
        shellSort(array, size, count_assign, count_compare, Time);
        break;
    case 10:
        shakerSort(array, size, count_assign, count_compare, Time);
        break;
    default:
        break;

    }
}