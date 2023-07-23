#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <cctype>
#include <unordered_set>

using namespace std;

//fuctions used for command1
int command1(ifstream &file, string algorithm, string input_file, string output_param, long long input_size,  long long &count_assign, long long &count_compare, float &Time, int* &array);
void output_for_command_1(string algorithm, string input_file, long long input_size, string output_param, long long count_compare, float Time);
void write_file(int *array, long long input_size);
void use_command1(ifstream  &file, string algorithm, string input_file, string output_param, long long &input_size,  long long &count_assign, long long &count_compare, float &Time, int *&array);

//fuctions used for command2
int generate_file(long long input_size, string input_order, int *&array);
int command2(string algorithm, string output_param, long long input_size,  long long &count_assign, long long &count_compare, float &Time, int* &array);
void output_for_command_2(string algorithm, string input_order, long long input_size, string output_param, long long count_compare, float Time);
void use_command2(string algorithm, string input_order, string output_param, long long &input_size,  long long &count_assign, long long &count_compare, float &Time, int *&array);

//fuctions used for command3
int generate_multiple_file(string algorithm, string output_param, long long input_size, int *&array_ran, int *&array_nsort, int *&array_sort, int *&array_rev);
void sort_array(string algorithm, long long input_size,  long long &count_assign, long long &count_compare, float &Time, int* &array);
void output_type_order(string order, string output_param, long long count_compare, float Time);
void output_for_command_3(string algorithm, long long input_size);
void use_command3(string algorithm, string output_param, long long &input_size, long long &count_assign_1, long long &count_compare_1, float &Time_1, long long &count_assign_2, long long &count_compare_2, float &Time_2,long long &count_assign_3, long long &count_compare_3, float &Time_3,long long &count_assign_4, long long &count_compare_4, float &Time_4, int *&array_ran, int *&array_nsort, int *&array_sort, int *&array_rev);

//fuctions used for command4
int command4(ifstream &file, string algorithm_1, string algorithm_2, string input_file, long long input_size, int* &array_1, int* &array_2);
void output_for_command_4(string algorithm_1, string algorithm_2, string input_file, long long input_size, long long count_compare_1, float Time_1, long long count_compare_2, float Time_2);
void use_command4(ifstream &file, string algorithm_1, string algorithm_2, string input_file, long long input_size, long long &count_assign_1, long long &count_compare_1, float &Time_1, long long &count_assign_2, long long &count_compare_2, float &Time_2, int *&array_1, int *&array_2);

//fuctions used for command5
int command5(string algorithm_1, string algorithm_2,long long input_size, string input_order, int *&array_1, int* &array_2);
void output_for_command_5(string algorithm_1, string algorithm_2, string input_order, long long input_size, long long count_compare_1, float Time_1, long long count_compare_2, float Time_2);
void use_command5(string algorithm_1, string algorithm_2, string input_order, long long input_size, long long &count_assign_1, long long &count_compare_1, float &Time_1, long long &count_assign_2, long long &count_compare_2, float &Time_2, int *&array_1, int *&array_2);

#endif