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
    void shell_sort_swap(vector<int>& arr){
        int size=arr.size();
        printVector(arr);
        // for(int gap=size/2;gap<size;gap/=2) gap must be greater than 0
        for(int gap=size/2;gap>0;gap/=2){
            for(int i=gap;i<size;i+=gap){
                int j=i-gap;
                while(j>=0&&arr[j]>arr[j+gap]){
                    swap(arr[j],arr[j+gap]);
                    j-=gap;
                    printVector(arr);
                }
            }
        }
    }

    void shell_sort_swap_desc(vector<int>& arr){
        int size=arr.size();
        printVector(arr);
        //for(int gap=size/2;gap<size;gap/=2) gap must be greater than 0
        for(int gap=size/2;gap>0;gap/=2){
            for(int i=gap;i<size;i+=gap){
                int j=i-gap;
                while(j>=0&&arr[j]<arr[j+gap]){
                    swap(arr[j],arr[j+gap]);
                    j-=gap;
                }
                printVector(arr);
            }
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

    void selection_sort_double_for_loop(vector<int>& arr){
        for(int i=0;i<arr.size();++i){
            printVector(arr);
            int min=arr[i];
            int index=i;
            for(int j=i+1;j<arr.size();++j){
                if(arr[j]<min){
                    min=arr[j];
                    index=j;
                }
            }
            swap(arr[index],arr[i]);
        }
    }

    void selection_sort_double_for_loop_desc(vector<int>& arr){
        for(int i=0;i<arr.size();++i){
            printVector(arr);
            int max=arr[i];
            int index=i;
            for(int j=i+1;j<arr.size();++j){
                if(arr[j]>max){
                    max=arr[j];
                    index=j;
                }
            }
            swap(arr[index],arr[i]);
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
    void shell_sort_wrong(vector<int> &arr)
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
    
    void merge_sort(vector<int>& arr,int left,int right){
        if(left<right){
            int mid=(left+right)/2;
            merge_sort(arr,left,mid);
            merge_sort(arr,mid+1,right);
            merge(arr,left,mid,right);
        }
    }

    void merge(vector<int>& arr,int left, int mid, int right){
        int nl=mid-left+1;
        int nr=right-mid;
        vector<int> l(nl),r(nr);
        for(int i=0;i<nl;++i){
            l[i]=arr[left+i];
        }
        for(int i=0;i<nl;++i){
            r[i]=arr[i+mid+1];
        }
        int i=0,j=0,k=left;
        while(i<nl&&j<nr){
            if(l[i]<=r[j]){
                arr[k]=l[i];
                ++i;
            }
            else{
                arr[k]=r[j];
                ++j;
            }
            ++k;
        }
        while(i<nl){
            arr[k]=l[i];
            ++k;
            ++i;
        }
        while(j<nr){
            arr[k]=r[j];
            ++k;
            ++j;
        }
    }

    int partition(vector<int>& arr,int left, int right){
        int pivot=arr[left];
        int i=left,j=left+1;
        for(int j=left+1;j<=right;++j){
            if(arr[j]<=pivot){
                ++i;
                swap(arr[j],arr[i]);
            }
       }
       swap(arr[left],arr[i]);
       return i;
    }

    void quick_sort(vector<int>& arr, int left, int right){
        if(left>=right){
            printVector(arr);
            return;
        }
        else{
            // printVector(arr);
            int middle=partition(arr,left,right);
            quick_sort(arr,left,middle-1);
            quick_sort(arr,middle+1,right);
        }
    }
}




