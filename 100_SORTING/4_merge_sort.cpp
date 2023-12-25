#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high)
    {    
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
     int index=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[index++];
    }
}

void merge_Sort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;

    int mid = (low + high) / 2;
    merge_Sort(arr, low, mid);
    merge_Sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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
    merge_Sort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
       cout<< arr[i]<<" ";
    }


    return 0;
}