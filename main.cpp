#include <iostream>
#include "sortlib.h"
// #include "sortlib.cpp"
using namespace std;
using namespace sortlib;
int main() {
    vector<int> arr={4,3,6,2,8,9,5};
    vector<int> a={1,2,3,4,5,6,7,8,9};
    vector<int> b={1,2,3,4,5,6,7,8,9};
    // selection_sort_double_for_loop_desc(arr);
    // shell_sort_swap(arr);
    // cout<<endl;
    // shell_sort_swap_desc(a);
    // selection_sort_desc(arr);
    // merge_sort(arr,0,arr.size()-1);
    quick_sort(arr,0,arr.size()-1);
    return 0;
}


    // int min=minimum(a,0);
    // cout<<min;
    // cout<<endl;
    // int index=minIndex(arr,0);
    // cout<<index;
    // cout<<endl;
    // selection_sort(a);
    // cout<<endl;
    // bubble_sort(a);
    // insertion_sort(arr);
    // cout<<endl;
    // insertion_sort_swap(a);
    // cout<<endl;
    // insertion_sort_desc(arr);
    // bubble_sort_desc(a);
    // bubble_sort(a);
    // cout<<"optimized \n";
    // bubble_sort_optimized(b);