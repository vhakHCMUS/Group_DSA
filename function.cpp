#include "function.h"
#include "SortAlg.h"
#include "DataGenerator.h"

using namespace std;

int command1(ifstream &file, string algorithm, string input_file, string output_param, long long input_size,  long long &count_assign, long long &count_compare, float &Time, int* &array)
{
    if (output_param != "-both")
    {
        if (output_param != "-time")
        {
            if (output_param != "-comp") return 1;
        }
    }

    vector<int> data;
    int num = 0;
   

    while (file >> num)
    {
        data.push_back(num);
    }
    
    for (int i = 0; i < input_size; i++)
    {
        array[i] = data[i];
    }

    if (algorithm == "selection-sort")
    {
        selectionSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "insertion-sort")
    {
        insertionSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "bubble-sort")
    {
        bubbleSort(array, input_size, count_assign, count_compare, Time);
    } 
    else if (algorithm == "heap-sort")
    {
        heapSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "counting-sort")
    {
        countingSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "radix-sort")
    {
        radixSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "quick-sort")
    {
        qSortCount(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "merge-sort")
    {
        mergeSortCount(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "shell-sort")
    {
        shellSort(array, input_size, count_assign, count_compare, Time);
    
    }
    else if (algorithm == "shaker-sort")
    {
        shakerSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "flash-sort")
    {
        flashSort(array, input_size, count_assign, count_compare, Time);
    }
    else return 2;

    return 0;
}

void output_for_command_1(string algorithm, string input_file, long long input_size, string output_param, long long count_compare, float Time)
{
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input file: " << input_file << endl; 
    cout << "Input size: " << input_size << endl;
    cout << "-------------------------\n";
    
    if (output_param == "-both")
    {
        cout << "Running time: " << Time << endl;
        cout << "Comparison: " << count_compare << endl;
    }
    else if (output_param == "-comp")
    {
        cout << "Comparison: " << count_compare << endl;
    }
    else if (output_param == "-time")
    {
        cout << "Running time: " << Time << endl;
    }
}

void write_file(int *array, long long input_size)
{
    ofstream fout("output.txt");

    fout << input_size << endl;

    for (int i = 0; i < input_size; i++) fout << array[i] << " ";

    fout.close();
}

void use_command1(ifstream  &file, string algorithm, string input_file, string output_param, long long &input_size,  long long &count_assign, long long &count_compare, float &Time, int *&array)
{

    int result = command1(file, algorithm, input_file, output_param, input_size, count_assign, count_compare, Time, array);
    switch (result)
    {
        case 1:
        {
            cout << "Unknown output param!\n";
            break;
        }
        case 2:
        {
            cout << "Unknown algorithm!\n";
            break;
        }
        case 0:
        {
            output_for_command_1(algorithm, input_file, input_size, output_param, count_compare, Time);
            write_file(array, input_size);
            break;
        }
    }
}

int generate_file(long long input_size, string input_order, int *&array)
{
    ofstream fout("input.txt");

    if (input_order == "-rand")
    {
        GenerateRandomData(array, input_size);
    }
    else if (input_order == "-nsorted")
    {
        GenerateNearlySortedData(array, input_size);
    }
    else if (input_order == "-sorted")
    {
        GenerateSortedData(array, input_size);
    }
    else if (input_order == "-rev")
    {
        GenerateReverseData(array, input_size);
    }
    else return 1;

    fout << input_size << endl;

    for (int i = 0; i < input_size; i++) fout << array[i] << " ";
    fout.close();

    return 0;
}

int command2(string algorithm, string output_param, long long input_size,  long long &count_assign, long long &count_compare, float &Time, int* &array)
{
    
    if (output_param != "-both")
    {
        if (output_param != "-time")
        {
            if (output_param != "-comp") return 1;
        }
    }

    if (algorithm == "selection-sort")
    {
        selectionSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "insertion-sort")
    {
        insertionSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "bubble-sort")
    {
        bubbleSort(array, input_size, count_assign, count_compare, Time);
    } 
    else if (algorithm == "heap-sort")
    {
        heapSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "counting-sort")
    {
        countingSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "radix-sort")
    {
        radixSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "quick-sort")
    {
        qSortCount(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "merge-sort")
    {
        mergeSortCount(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "shell-sort")
    {
        shellSort(array, input_size, count_assign, count_compare, Time);
    
    }
    else if (algorithm == "shaker-sort")
    {
        shakerSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "flash-sort")
    {
        flashSort(array, input_size, count_assign, count_compare, Time);
    }
    else return 2;

    return 0;

}
void output_for_command_2(string algorithm, string input_order, long long input_size, string output_param, long long count_compare, float Time)
{
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << input_size << endl;
    cout << "Input order: " << input_order << endl;
    cout << "-------------------------\n";
    
    if (output_param == "-both")
    {
        cout << "Running time: " << Time << endl;
        cout << "Comparison: " << count_compare << endl;
    }
    else if (output_param == "-comp")
    {
        cout << "Comparison: " << count_compare << endl;
    }
    else if (output_param == "-time")
    {
        cout << "Running time: " << Time << endl;
    }
}

void use_command2(string algorithm, string input_order, string output_param, long long &input_size,  long long &count_assign, long long &count_compare, float &Time, int *&array)
{

    int result1 = generate_file(input_size, input_order, array);
    if (result1 == 1)
    {
        cout << "Unknown input order\n";
        return;
    }
    int result2 =  command2(algorithm, output_param, input_size, count_assign, count_compare, Time, array);
    switch (result2)
    {
        case 1:
        {
            cout << "Unknown output param!\n";
            break;
        }
        case 2:
        {
            cout << "Unknown algorithm!\n";
            break;
        }
        case 0:
        {
            output_for_command_2(algorithm, input_order, input_size, output_param, count_compare, Time);
            break;
        }
    }
}

int generate_multiple_file(string algorithm, string output_param, long long input_size, int *&array_ran, int *&array_nsort, int *&array_sort, int *&array_rev)
{
    unordered_set<string> validAlgorithms = {"selection-sort", "merge-sort", "radix-sort", "bubble-sort", "quick-sort", "counting-sort", "heap-sort", "insertion-sort", "shell-sort", "shaker-sort", "flash-sort"};
    
    // Check if the algorithm is one of the specified options
    if (validAlgorithms.find(algorithm) == validAlgorithms.end()) return 1;

    if (output_param != "-both")
    {
        if (output_param != "-time")
        {
            if (output_param != "-comp") return 2;
        }
    }
    
    ofstream fout_1("input_1.txt");
    ofstream fout_2("input_2.txt");
    ofstream fout_3("input_3.txt");
    ofstream fout_4("input_4.txt");
    
    GenerateRandomData(array_ran, input_size);
    GenerateNearlySortedData(array_nsort, input_size);
    GenerateSortedData(array_sort, input_size);
    GenerateReverseData(array_rev, input_size);

    fout_1 << input_size << endl;
    fout_2 << input_size << endl;
    fout_3 << input_size << endl;
    fout_4 << input_size << endl;

    for (int i = 0; i < input_size; i++)
    {
        fout_1 << array_ran[i] << " ";
        fout_2 << array_nsort[i] << " ";
        fout_3 << array_sort[i] << " ";
        fout_4 << array_rev[i] << " ";
    } 

    fout_1.close();
    fout_2.close();
    fout_3.close();
    fout_4.close();

    return 0;
}

void sort_array(string algorithm, long long input_size,  long long &count_assign, long long &count_compare, float &Time, int* &array)
{
     if (algorithm == "selection-sort")
    {
        selectionSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "insertion-sort")
    {
        insertionSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "bubble-sort")
    {
        bubbleSort(array, input_size, count_assign, count_compare, Time);
    } 
    else if (algorithm == "heap-sort")
    {
        heapSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "counting-sort")
    {
        countingSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "radix-sort")
    {
        radixSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "quick-sort")
    {
        qSortCount(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "merge-sort")
    {
        mergeSortCount(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "shell-sort")
    {
        shellSort(array, input_size, count_assign, count_compare, Time);
    
    }
    else if (algorithm == "shaker-sort")
    {
        shakerSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "flash-sort")
    {
        flashSort(array, input_size, count_assign, count_compare, Time);
    }
}

void output_type_order(string order, string output_param, long long count_compare, float Time)
{
    cout << "Input order: " << order << endl;
    cout << "-------------------------\n";
    
    if (output_param == "-both")
    {
        cout << "Running time: " << Time << endl;
        cout << "Comparison: " << count_compare << endl;
    }
    else if (output_param == "-comp")
    {
        cout << "Comparison: " << count_compare << endl;
    }
    else if (output_param == "-time")
    {
        cout << "Running time: " << Time << endl;
    }
    cout << endl;
}

void output_for_command_3(string algorithm, long long input_size)
{
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << input_size << "\n\n";
}
void use_command3(string algorithm, string output_param, long long &input_size, long long &count_assign_1, long long &count_compare_1, float &Time_1, long long &count_assign_2, long long &count_compare_2, float &Time_2,long long &count_assign_3, long long &count_compare_3, float &Time_3,long long &count_assign_4, long long &count_compare_4, float &Time_4, int *&array_ran, int *&array_nsort, int *&array_sort, int *&array_rev)
{
    int result1 = generate_multiple_file(algorithm, output_param, input_size, array_ran, array_nsort, array_sort, array_rev);
    if (result1 == 1)
    {
        cout << "Unknown algorithm!\n";
        return;
    }
    else if (result1 == 2)
    {
        cout << "Unknown output param!\n";
        return;
    }

    sort_array(algorithm, input_size, count_assign_1, count_compare_1, Time_1, array_ran);
    sort_array(algorithm, input_size, count_assign_2, count_compare_2, Time_2, array_nsort);
    sort_array(algorithm, input_size, count_assign_3, count_compare_3, Time_3, array_sort) ;
    sort_array(algorithm, input_size, count_assign_4, count_compare_4, Time_4, array_rev);

    output_for_command_3(algorithm, input_size);
    string random = "Randomize";
    string nearly = "Nearly Sorted";
    string sorted = "Sorted";
    string rev = "Reversed";
    output_type_order(random, output_param, count_compare_1,Time_1);
    output_type_order(nearly, output_param, count_compare_2, Time_2);
    output_type_order(sorted, output_param, count_compare_3, Time_3);
    output_type_order(rev, output_param, count_compare_4, Time_4);
}

int command4(ifstream &file, string algorithm_1, string algorithm_2, string input_file, long long input_size, int* &array_1, int* &array_2)
{
    unordered_set<string> validAlgorithms = {"selection-sort", "merge-sort", "radix-sort", "bubble-sort", "quick-sort", "counting-sort", "heap-sort", "insertion-sort", "shell-sort", "shaker-sort", "flash-sort"};
    
    // Check if the algorithm is one of the specified options
    if (validAlgorithms.find(algorithm_1) == validAlgorithms.end() || validAlgorithms.find(algorithm_2) == validAlgorithms.end()) return 1;

    vector<int> data;
    int num = 0;   

    while (file >> num)
    {
        data.push_back(num);
    }
    for (int i = 0; i < input_size; i++)
    {
        array_1[i] = data[i];
        array_2[i] = data[i];
    }

    return 0;
}

void output_for_command_4(string algorithm_1, string algorithm_2, string input_file, long long input_size, long long count_compare_1, float Time_1, long long count_compare_2, float Time_2)
{
    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << algorithm_1 << " | " << algorithm_2 << endl;
    cout << "Input file: " << input_file << endl; 
    cout << "Input size: " << input_size << endl;
    cout << "-------------------------\n";
    
   
    cout << "Running time: " << Time_1 << " | " << Time_2 << endl;
    cout << "Comparison: " << count_compare_1 << " | " << count_compare_2 << endl;
   
}

void use_command4(ifstream &file, string algorithm_1, string algorithm_2, string input_file, long long input_size, long long &count_assign_1, long long &count_compare_1, float &Time_1, long long &count_assign_2, long long &count_compare_2, float &Time_2, int *&array_1, int *&array_2)
{
    int result = command4(file, algorithm_1, algorithm_2, input_file, input_size, array_1, array_2);
    switch(result)
    {
        case 1:
        {
            cout << "Unknown algorithm!\n";
            return;
        }
        case 2:
        {
            cout << "File not found!\n";
            return;
        }
        case 0:
        {
            sort_array(algorithm_1, input_size, count_assign_1, count_compare_1, Time_1, array_1);
            sort_array(algorithm_2, input_size, count_assign_2, count_compare_2, Time_2, array_2);
            output_for_command_4(algorithm_1, algorithm_2, input_file, input_size, count_compare_1, Time_1, count_compare_2, Time_2);
            write_file(array_1, input_size);
        }
    }
}

int command5(string algorithm_1, string algorithm_2,long long input_size, string input_order, int *&array_1, int* &array_2)
{
    unordered_set<string> validAlgorithms = {"selection-sort", "merge-sort", "radix-sort", "bubble-sort", "quick-sort", "counting-sort", "heap-sort", "insertion-sort", "shell-sort", "shaker-sort", "flash-sort"};
    
    // Check if the algorithm is one of the specified options
    if (validAlgorithms.find(algorithm_1) == validAlgorithms.end() || validAlgorithms.find(algorithm_2) == validAlgorithms.end()) return 1;


    ofstream fout("input.txt");

    if (input_order == "-rand")
    {
        GenerateRandomData(array_1, input_size);
        GenerateRandomData(array_2, input_size);
    }
    else if (input_order == "-nsorted")
    {
        GenerateNearlySortedData(array_1, input_size);
        GenerateNearlySortedData(array_2, input_size);
    }
    else if (input_order == "-sorted")
    {
        GenerateSortedData(array_1, input_size);
        GenerateSortedData(array_2, input_size);
    }
    else if (input_order == "-rev")
    {
        GenerateReverseData(array_1, input_size);
        GenerateReverseData(array_2, input_size);
    }
    else return 2;

    fout << input_size << endl;

    for (int i = 0; i < input_size; i++) fout << array_1[i] << " ";
    fout.close();

    return 0;
}

void output_for_command_5(string algorithm_1, string algorithm_2, string input_order, long long input_size, long long count_compare_1, float Time_1, long long count_compare_2, float Time_2)
{
    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << algorithm_1 << " | " << algorithm_2 << endl;
    cout << "Input size: " << input_size << endl;
    cout << "Input order: " << input_order << endl; 
    cout << "-------------------------\n";
    
   
    cout << "Running time: " << Time_1 << " | " << Time_2 << endl;
    cout << "Comparison: " << count_compare_1 << " | " << count_compare_2 << endl;
}

void use_command5(string algorithm_1, string algorithm_2, string input_order, long long input_size, long long &count_assign_1, long long &count_compare_1, float &Time_1, long long &count_assign_2, long long &count_compare_2, float &Time_2, int *&array_1, int *&array_2)
{
    int result = command5(algorithm_1, algorithm_2, input_size, input_order, array_1, array_2);
    switch (result)
    {
        case 1:
        {
            cout << "Unknown algorithm!\n";
            return;
        }
        case 2:
        {
            cout << "Unknown input order!\n";
            return;
        }
        case 0:
        {
            sort_array(algorithm_1, input_size, count_assign_1, count_compare_1, Time_1, array_1);
            sort_array(algorithm_2, input_size, count_assign_2, count_compare_2, Time_2, array_2);
            output_for_command_5(algorithm_1, algorithm_2, input_order, input_size, count_compare_1, Time_1, count_compare_2, Time_2);
        }
    }
}
