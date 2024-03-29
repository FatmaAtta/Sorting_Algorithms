#include "sortlib.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using namespace sortlib;

void printVector(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << "| " << setw(3) << i << " |";
    }
    cout << "\n";
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// returns the minimum number
int minimum(vector<int> &arr, int start)
{
    int min = arr[start];
    for (int i = start + 1; i < arr.size(); ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
// returns the minimum index
int minIndex(vector<int> &arr, int start)
{
    int min = start;
    for (int i = start + 1; i < arr.size(); ++i)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    return min;
}

int minIndexEnd(vector<int> &arr, int end)
{
    int min = end;
    for (int i = 0; i < end; ++i)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    return min;
}

namespace sortlib
{

    void insertion_sort(vector<int> &arr)
    {
        int temp;
        for (int i = 1; i < arr.size(); ++i)
        {
            printVector(arr);
            temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                // arr[j]=0;
                --j;
            }
            arr[j + 1] = temp;
            // printVector(arr);
        }
    }

    void insertion_sort_swap(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); ++i)
        {
            printVector(arr);
            int j = i - 1;
            while (j >= 0 && arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                --j;
            }
        }
        printVector(arr);
    }

    void insertion_sort_desc(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); ++i)
        {
            printVector(arr);
            int j = i - 1;
            while (j >= 0 && arr[j + 1] > arr[j])
            {
                swap(arr[j + 1], arr[j]);
                --j;
            }
        }
        printVector(arr);
    }

    void selection_sort(vector<int> &arr)
    {
        printVector(arr);
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            swap(arr[i], arr[minIndex(arr, i)]);
            printVector(arr);
        }
    }

    void selection_sort_desc(vector<int> &arr)
    {
        printVector(arr);
        for (int i = arr.size() - 1; i >= 0; --i)
        {
            swap(arr[i], arr[minIndexEnd(arr, i)]);
            printVector(arr);
        }
    }

    void bubble_sort(vector<int> &arr)
    {
        printVector(arr);
        for (int j = arr.size() - 1; j >= 0; --j)
        {
            for (int i = 0; i < j; ++i)
            {
                if (arr[i] > arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                }
                printVector(arr);
            }
        }
    }

    void bubble_sort_desc(vector<int> &arr)
    {
        printVector(arr);
        for (int j = arr.size() - 1; j >= 0; --j)
        {
            for (int i = 0; i < j; ++i)
            {
                if (arr[i] < arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                }
                printVector(arr);
            }
        }
    }

    void bubble_sort_optimized(vector<int> &arr)
    {
        bool change = false;
        printVector(arr);
        for (int j = arr.size() - 1; j >= 0; --j)
        {
            for (int i = 0; i < j; ++i)
            {
                if (arr[i] > arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                    change = true;
                }
                printVector(arr);
            }
            if (!change)
            {
                break;
            }
        }
    }

    //wrong implementation
    void shell_sort(vector<int> &arr)
    {
        int n = arr.size();
        int jump =n/2;
        printVector(arr);
        while(jump>=0){
            for(int i=0;i<jump;++i){
                for(int j=i;j<n-jump;j+=jump){
                    if(arr[j]>arr[j+jump]){
                        swap(arr[j],arr[j+jump]);
                    }
                }
            }
            jump/=2;
            printVector(arr);
        }
    }
}