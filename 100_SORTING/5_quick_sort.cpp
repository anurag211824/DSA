#include <bits/stdc++.h>
using namespace std;
int partition_Index(vector<int> &arr, int low, int high)
{
    int left = low;
    int right = high;
    int pivot = arr[low];
    while (left < right)
    {
        while (arr[left] <= pivot && left <high)
        left++;

        while (arr[right] > pivot && right >low)
        right--;


        if(left<right)
        swap(arr[left],arr[right]);
      
    }
    swap(arr[low],arr[right]);
    return right;
}
void quick_sort(vector<int> &arr,int low,int high){
if(low<high){
    int p=partition_Index(arr,low,high);
    quick_sort(arr,low,p-1);
    quick_sort(arr,p+1,high);
}
}

int main()
{
    vector<int> arr(100);
    int n;
    cout << "enter n:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr,0,n-1);
     for (int i = 0; i < n; i++)
    {
       cout<< arr[i]<<" ";
    }



    return 0;
}