#include <iostream>
using namespace std;

void display(int arr[], int *size)
{
    for (int i = 0; i < *size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int insertion(int arr[], int ele, int *size, int *capacity, int index)
{
    if (*size >= *capacity)
        return -1;
    for (int i = *size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = ele;
    (*size)++;
    return 1;
}

int main()
{
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    display(arr, &size);
    int ele = 500, index = 2, capacity = 15;
    int result = insertion(arr, ele, &size, &capacity, index);
    if (result == -1)
        cout << "insertion failed";
    else
    {
        cout << "dispalying the modified array after insertion" << endl;
        display(arr, &size);
    }
    cout << "new size of array after insertion is:";
    cout << size;

    return 0;
}