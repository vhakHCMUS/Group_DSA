#include <iostream>
#include "function.h"
#include "DataGenerator.h"
#include "SortAlg.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 5)
    {
        cout << "Not found command line!\n";
        return 1;
    }

    string mode = argv[1];
    

    if (mode == "-a")
    {
        string algorithm = argv[2];
        long long count_assign = 0;
        long long count_compare = 0;
        float Time = 0;
        if (argc == 5)
        {
            if (!isalpha(argv[3][0]))
            {
                string input_size_line = argv[3];
                long long input_size = stoll(input_size_line);
                string output_param = argv[4];
                long long count_assign_1 = 0;
                long long count_compare_1 = 0;
                float Time_1 = 0;
                long long count_assign_2 = 0;
                long long count_compare_2 = 0;
                float Time_2 = 0;
                long long count_assign_3 = 0;
                long long count_compare_3 = 0;
                float Time_3 = 0;
                long long count_assign_4 = 0;
                long long count_compare_4 = 0;
                float Time_4 = 0;
                int *array_ran = new int[input_size];
                int *array_nsort = new int[input_size];
                int *array_sort = new int[input_size];
                int *array_rev = new int[input_size];
                use_command3(algorithm, output_param, input_size, count_assign_1, count_compare_1, Time_1, count_assign_2, count_compare_2, Time_2, count_assign_3, count_compare_3, Time_3, count_assign_4, count_compare_4, Time_4, array_ran, array_nsort, array_sort, array_rev);
            }
            else 
            { 
                string input_file = argv[3];
                string output_param = argv[4];
                ifstream file(input_file);

                if (!file.is_open())
                {
                    cout << "File not found!\n";
                    return 1;
                }
                
                long long input_size = 0;
                file >> input_size;
                int *array = new int[input_size];

                use_command1(file, algorithm, input_file, output_param, input_size, count_assign, count_compare, Time, array);
                file.close();
            }
           
        }
        else if (argc == 6)
        {
            string input_size_line = argv[3];
            long long input_size = stoll(input_size_line);
            string input_order = argv[4];
            string output_param = argv[5];
            int *array = new int[input_size];

            use_command2(algorithm, input_order, output_param, input_size, count_assign, count_compare, Time,  array);

        }
    }
    else if (mode == "-c")
    {
        string algorithm_1 = argv[2];
        string algorithm_2 = argv[3];
        long long count_assign_1 = 0;
        long long count_compare_1 = 0;
        float Time_1 = 0;
        long long count_assign_2 = 0;
        long long count_compare_2= 0;
        float Time_2 = 0;

        if (argc == 5)
        {
            string input_file = argv[4];
            ifstream file(input_file);
            if (!file.is_open())
            {
                cout << "File not found!\n";
                return 1;
            }
            
            long long input_size = 0;
            file >> input_size;
            
            int *array_1 = new int[input_size];
            int *array_2 = new int[input_size];

            use_command4(file, algorithm_1, algorithm_2, input_file, input_size, count_assign_1, count_compare_1, Time_1, count_assign_2, count_compare_2, Time_2, array_1, array_2);
            file.close();
        }
        else if (argc == 6)
        {
            string input_size_line = argv[4];
            long long input_size = stoll(input_size_line);
            string input_order = argv[5];
            int *array_1 = new int[input_size];
            int *array_2 = new int[input_size];

            use_command5(algorithm_1, algorithm_2, input_order, input_size, count_assign_1, count_compare_1, Time_1, count_assign_2, count_compare_2, Time_2, array_1, array_2);
        }
    }

    return 0; 
}


