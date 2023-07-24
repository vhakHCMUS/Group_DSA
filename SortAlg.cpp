#include "SortAlg.h"
#include <iostream>
#include <time.h>

using namespace std;

void selectionSortTime(int* array, int size, long long &count_assign, long long& count_compare, float& Time)
{
    //apply clock to count the time
    clock_t start, end, total;
    start = clock();
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            count_compare++;
            if(array[j]<array[min])
            {
                min=j;
            }
        }
        swap(array[min],array[i]);
    }
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

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

void insertionSortTime(int* array, int size, long long&count_assign, long long& count_compare, float& Time)
{
    clock_t start, end, total;
    start = clock();
    for(int i=1;i<size;i++)
    {
        int key=array[i];
        int j=i-1;
        while((j>=0)&&(array[j]>key))
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

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

void bubbleSortTime(int* array, int size, long long &count_assign, long long& count_compare, float& Time)
{
    clock_t start, end, total;
    start = clock();
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                swap(array[j],array[j+1]);
            }
        }
    }
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

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

void heapifyTime(int* array, int size, int i, long long& count_assign, long long& count_compare)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<size&&array[l]>array[largest])
    {
        largest=l;
    }
    if(r<size&&array[r]>array[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(array[i],array[largest]);
        heapify(array,size,largest,count_assign,count_compare);
    }
}
void heapSortTime(int* array, int size, long long & count_assign, long long& count_compare, float& Time)
{
    clock_t start, end, total;
    start = clock();
    for(int i=size/2-1;i>=0;i--)
    {
        heapifyTime(array,size,i,count_assign,count_compare);
    }
    for(int i=size-1;i>=0;i--)
    {
        swap(array[0],array[i]);
        heapifyTime(array,i,0,count_assign,count_compare);
    }
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

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

void countingSortTime(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
    int max=array[0];
    clock_t start, end, total;
    start = clock();
    for(int i=1;i<size;i++)
    {
        if(array[i]>max)
        {
            max=array[i];
        }
    }
    int* count=new int[max+1];
    for(int i=0;i<max+1;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<size;i++)
    {
        count[array[i]]++;
    }
    int index=0;
    for(int i=0;i<max+1;i++)
    {
        while(count[i]>0)
        {
            array[index]=i;
            index++;
            count[i]--;
        }
    }
    delete[] count;
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

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
void radixSortTime(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
    clock_t start, end, total;
    start = clock();
    int max=array[0];
    for(int i=1;i<size;i++)
    {
        if(array[i]>max)
        {
            max=array[i];
        }
    }
    for(int exp=1;max/exp>0;exp*=10)
    {
        int* output=new int[size];
        int count[10]={0};
        for(int i=0;i<size;i++)
        {
            count[(array[i]/exp)%10]++;
        }
        for(int i=1;i<10;i++)
        {
            count[i]+=count[i-1];
        }
        for(int i=size-1;i>=0;i--)
        {
            output[count[(array[i]/exp)%10]-1]=array[i];
            count[(array[i]/exp)%10]--;
        }
        for(int i=0;i<size;i++)
        {
            array[i]=output[i];
        }
        delete[] output;
    }
    end = clock();
    total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}

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
int medianOfThree(int* array, int low, int high, long long& count_compare)
{
    int mid = low + (high - low) / 2;

    // Compare array[low], array[mid], and array[high], and return the median index.
    if (count_compare++, array[low] <= array[mid])
    {
        if (count_compare++, array[mid] <= array[high])
        {
            return mid;
        }
        else if (count_compare++, array[low] <= array[high])
        {
            return high;
        }
        return low;
    }
    else
    {
        if (count_compare++, array[low] <= array[high])
        {
            return low;
        }
        else if (count_compare++, array[mid] <= array[high])
        {
            return high;
        }
        return mid;
    }
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* array, int low, int high, long long& count_assign, long long& count_compare)
{
    int pivotIdx = medianOfThree(array, low, high, count_compare);
    swap(array[pivotIdx], array[high]);
    int pivot = array[high];

    int i = low - 1;
    count_assign += 3;

    for (int j = low; count_compare++, j <= high - 1; count_assign++, j++)
    {
        if (count_compare++, array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
            count_assign += 4;
        }
    }

    swap(array[i + 1], array[high]);
    count_assign += 3;

    return i + 1;
}

void quickSort(int* array, int low, int high, long long& count_assign, long long& count_compare)
{
    if(++count_compare && low<high)
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
    count_compare=0;
    start = clock();
    quickSort(array,low, high, count_assign, count_compare);
    end = clock();
	total = end - start;
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
    if (++count_compare && l < r) {
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
	total = end - start;
    Time = (float)total/CLOCKS_PER_SEC;
}
//write shellSort and count the number of assignments and comparisons

void shellSortTime(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
    clock_t start, end;
    start = clock();

    // Shell sort implementation
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; ++i)
        {
            int temp = array[i];
            int j = i;

            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }
    }

    end = clock();
    Time = (float)(end - start) / CLOCKS_PER_SEC;
}
void shellSort(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
    count_assign = 0;
    count_compare = 0;
    clock_t start, end;
    start = clock();

    // Shell sort implementation
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; ++i)
        {
            int temp = array[i];
            int j = i;

            count_assign += 2;
            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
                count_assign += 2;
                count_compare++;
            }

            array[j] = temp;
            count_assign++;
            
            count_compare++; // Increment comparison count for the for loop
        }
    }

    end = clock();
    Time = (float)(end - start) / CLOCKS_PER_SEC;
}


//write shakerSort and count the number of assignments and comparisons
void shakerSortTime(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
    clock_t start, end;
    start = clock();

    // Shaker sort implementation
    int left = 0;
    int right = size - 1;
    bool swapped = false;

    while (left < right)
    {
        // Forward pass: move the largest element to the right
        for (int i = left; i < right; ++i)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
        --right;

        // Backward pass: move the smallest element to the left
        for (int i = right; i > left; --i)
        {
            if (array[i - 1] > array[i])
            {
                swap(array[i - 1], array[i]);
                swapped = true;
            }
        }
        ++left;

        // If no elements were swapped in either pass, the array is sorted
        if (!swapped)
            break;
        else
            swapped = false;

    }

    end = clock();
    Time = (float)(end - start) / CLOCKS_PER_SEC;
}

void shakerSort(int* array, int size, long long& count_assign, long long& count_compare, float& Time)
{
    count_assign = 0;
    count_compare = 0;
    clock_t start, end;
    start = clock();

    // Shaker sort implementation
    int left = 0;
    int right = size - 1;
    bool swapped = false;

    while (left < right)
    {
        // Forward pass: move the largest element to the right
        for (int i = left; i < right; ++i)
        {
            count_compare++;
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                count_assign += 3;
                swapped = true;
            }
            count_assign++; // Increment assignment count for the for loop
        }
        --right;

        // Backward pass: move the smallest element to the left
        for (int i = right; i > left; --i)
        {
            count_compare++;
            if (array[i - 1] > array[i])
            {
                swap(array[i - 1], array[i]);
                count_assign += 3;
                swapped = true;
            }
            count_assign++; // Increment assignment count for the for loop
        }
        ++left;

        // If no elements were swapped in either pass, the array is sorted
        if (!swapped)
            break;
        else
            swapped = false;

        count_compare++; // Increment comparison count for the while loop
    }

    end = clock();
    Time = (float)(end - start) / CLOCKS_PER_SEC;
}
//write flashSort and count the number of assignments and comparisons
void flashSortTime(int* array, int size,long long& count_assign,long long& count_compare,float&Time) {
    clock_t start, end, total;
    start = clock();
    if ( size <= 1) {
        end = clock();
        total = end - start;
        Time = (float)total / CLOCKS_PER_SEC;
        return;
    }
    int m = size * 0.43;
    if (m <= 2) {
        m = 2;
    }
    
    // int m = n;
    int* __L = new int[m];
    for (int i = 0; i < m; ++i) {
        __L[i] = 0;
    }
    int Mx = array[0], Mn = array[0];

    for (int i = 1;i < size;++i) {
        if (Mx < array[i]) {
            Mx = array[i];
        }
        if (Mn > array[i]) {
            Mn = array[i];
        }
    }
    if (count_compare++ && Mx == Mn) {
        end = clock();
        total = end - start;
        Time = (float)total / CLOCKS_PER_SEC;
        return;
    }
        
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0;i < size;++i) {
        ++__L[getK(array[i])];
    }

    for (int i = 1; i < m;  ++i) {
        __L[i] += __L[i - 1];
    }
    //step 2
    int count = 0;
    int i = 0;
    while (count < size) {
        int k = getK(array[i]);
        while (i >= __L[k])
            k = getK(array[++i]);
        int z = array[i];
        count_assign += 2;
        while (i != __L[k]) {
            k = getK(z);
            int y = array[__L[k] - 1];
            array[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    //step 3

    for (int k = 1; k < m;++k) {
        for (int i = __L[k] - 2;i >= __L[k - 1];--i)
            if ( array[i] > array[i + 1]) {
                int t = array[i], j = i;
                while (t > array[j + 1]) { 
                array[j] = array[j + 1]; 
                ++j;
            }
                array[j] = t;
        }
    }
    delete[]__L;
    end = clock();
    total = end - start;
    Time = (float)total / CLOCKS_PER_SEC;
}
void flashSort(int* array, int size,long long& count_assign,long long& count_compare,float&Time) {
    count_assign = 0;
    count_compare = 0;
    clock_t start, end, total;
    start = clock();
    if (++count_compare && size <= 1) {
        end = clock();
        total = end - start;
        Time = (float)total / CLOCKS_PER_SEC;
        return;
    }
    int m = size * 0.43;
    if (count_compare++ && m <= 2) {
        m = 2;
        count_assign++;
    }
    
    // int m = n;
    int* __L = new int[m];
    count_assign++;
    for (int i = 0; count_compare++, i < m; count_assign++, ++i) {
        __L[i] = 0;
        count_assign++;
    }
    int Mx = array[0], Mn = array[0];
    count_assign += 3;
    for (int i = 1;count_compare++, i < size;count_assign++, ++i) {
        if (count_compare++ && Mx < array[i]) {
            Mx = array[i];
            count_assign++;
        }
        if (count_compare++ && Mn > array[i]) {
            Mn = array[i];
            count_assign++;
        }
    }
    if (count_compare++ && Mx == Mn) {
        end = clock();
        total = end - start;
        Time = (float)total / CLOCKS_PER_SEC;
        return;
    }
        
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    count_assign++;
    for (int i = 0; count_compare++, i < size; count_assign++, ++i) {
        ++__L[getK(array[i])];
        count_assign++;
    }
    count_assign++;
    for (int i = 1; count_compare++, i < m; count_assign++, ++i) {
        __L[i] += __L[i - 1];
        count_assign++;
    }
    //step 2
    int count = 0;
    int i = 0;
    count_assign += 2;
    while (count_compare++ && count < size) {
        int k = getK(array[i]);
        count_assign++;
        while (count_compare++ && i >= __L[k])
            k = getK(array[++i]);
        int z = array[i];
        count_assign += 2;
        while (count_compare++ && i != __L[k]) {
            k = getK(z);
            int y = array[__L[k] - 1];
            array[--__L[k]] = z;
            z = y;
            ++count;
            count_assign += 5;
        }
    }
    //step 3
    count_assign++;
    for (int k = 1;count_compare++, k < m;count_assign++, ++k) {
        count_assign++;
        for (int i = __L[k] - 2;count_compare++, i >= __L[k - 1];count_assign++, --i)
            if (count_compare++ && array[i] > array[i + 1]) {
                int t = array[i], j = i;
                count_assign += 2;
                while (count_compare++ && t > array[j + 1]) { 
                array[j] = array[j + 1]; 
                ++j;
                count_assign += 2;
            }
                array[j] = t;
                count_assign++;
        }
    }
    delete[]__L;
    end = clock();
    total = end - start;
    Time = (float)total / CLOCKS_PER_SEC;
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
    case 11:
        flashSort(array, size, count_assign, count_compare, Time);
        break;
    default:
        break;

    }
}
