#ifndef DS_ASSIG1_SORTLIB_H
#define DS_ASSIG1_SORTLIB_H

#include <vector>
using namespace std;

void printVector(vector<int>&arr);

void swap(int& a, int& b);

int minimum(vector<int>& arr, int start);

int minIndex(vector<int>& arr, int start);

int minIndexEnd(vector<int>& arr, int end);

namespace sortlib{
    void insertion_sort(vector<int>& arr);
    void insertion_sort_swap(vector<int>& arr);
    void insertion_sort_desc(vector<int>& arr);
    void selection_sort(vector<int>& arr);
    void selection_sort_desc(vector<int>& arr);
    void bubble_sort(vector<int>& arr);
    void bubble_sort_optimized(vector<int>& arr);
    void bubble_sort_desc(vector<int>& arr);
    void shell_sort_wrong(vector<int>& arr);
    void shell_sort(vector<int>& arr);
}

#endif //DS_ASSIG1_SORTLIB_H
