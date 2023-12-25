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
void deletion(int arr[], int *size, int index)
{
    for (int i = index; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
int main()
{
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    display(arr, &size);
    int index = 2;
    deletion(arr, &size, index);
    cout << "display the modified array after deletion" << endl;
    display(arr, &size);
    cout << "new size of array after deletion is:";
    cout << size;

    return 0;
}