// #include <iostream>

// using namespace std;
// int greatest_common_divisor(int n1, int n2)
// {
//     if (n2 == 0)
//         return n1;
//     else
//     {
//         int a = n1 % n2;
//         greatest_common_divisor(n2, a);
//     }
// }
// int iterative_greatest_common_divisor(int m1, int m2)
// {
//     if (m1 > m2)
//     {
//         int a;
//         for (int i = 1; i <= m1; i++)
//         {
//             if (m1 % i == 0 && m2 % i == 0)
//                 a = i;
//         }
//         return a;
//     }
//     else
//     {
//         int b;
//         for (int i = 1; i <= m2; i++)
//         {
//             if (m1 % i == 0 && m2 % i == 0)
//                 b = i;
//         }
//         return b;
//     }
// }

// int main()
// {
//     int x;
//     int y;
//     cout << "enter x and y :";
//     cin >> x >> y;
//     int result1 = greatest_common_divisor(x, y);
//     cout << "the gcd is:";
//     cout << result1;
//     cout << endl;
//     int result2 = iterative_greatest_common_divisor(x, y);
//     cout << "the gcd is:";
//     cout << result2;
//     return 0;
// }

int peakElement(int arr[], int n)
{
    if (n == 1)
    {
        return 0;
    }
    int i = 0;
    int j = i + 1;
    int k = j + 1;
    int a = 1;
    while (a != n - 1)
    {
        if (arr[i] <= arr[j] && arr[j] >= arr[k])
            return j;

        else if (k == n)
        {

            arr[k] = arr[j] - 1;
        }
        else
        {

            i++;
            j++;
            k++;
            a++;
        }
    }
}