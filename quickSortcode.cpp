#include <iostream>
#include<vector>
using namespace std;
int partition(vector<int>& arr, int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int  i = s+1; i<= e; i++){
        if(arr[i]<= pivot){
            cnt++;
        }
    }
   
    int pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);

    //left elements less than than pivot and right elemets greater than pivot
    int i=s, j =e;
    while(i< pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if(i> pivotIndex && j < pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
return pivotIndex;
}
void solve(vector<int>& arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }

    //partition
    int p = partition(arr, s, e);
    //recursion

   solve(arr, s, p-1);
   solve(arr, p+1, e);
}
vector<int> quickSort(vector<int> arr)
{
    solve(arr, 0, arr.size()-1);
    return arr;
}