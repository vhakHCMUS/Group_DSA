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
                cout << "Data type: " << dataType << " Data size: " << dataSize << " Sort type: " << sortType << " Assign: " << count_assign << " Compare: " << count_compare << " Time: " << Time << endl;
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
                cout << "Data type: " << dataType << " Data size: " << dataSize << " Sort type: " << sortType << " Assign: " << count_assign << " Compare: " << count_compare << " Time: " << Time << endl;
            }
            delete[] array;
        }
    }

}