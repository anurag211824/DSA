#include <iostream>

using namespace std;
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}
int binarySearch(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == element)
            return mid;

        else if (arr[mid] < element)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(int);
    int element = 0;
    int result = linearSearch(arr, size, element);
    if(result!=-1)
    cout<<"the desired element found at index:"<<result<<endl;
    else
     cout<<"the desired element not found"<<endl;

     int result1 =binarySearch(arr, size, element);
     if(result1!=-1)
    cout<<"the desired element found at index:"<<result1<<endl;
    else
    cout<<"the desired element not found"<<endl;

    return 0;
}