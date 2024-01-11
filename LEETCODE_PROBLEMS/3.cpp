#include <iostream>
#include <cmath>
using namespace std;
int findEqualPoint(string str)
{
    int total_length = str.length();
    int open[total_length + 1] = {0}, close[total_length + 1] = {0};
    int index = -1;
    open[0] = 0;
    close[total_length] = 0;
    if (str[0] == '(') // check whether first bracket is opening or not, if so mark open[1] = 1
        open[1] = 1;
    if (str[total_length - 1] == ')') // check whether first bracket is closing or not, if so mark       close[end] = 1
        close[total_length - 1] = 1;
    for (int i = 1; i < total_length; i++)
    {
        if (str[i] == '(')
            open[i + 1] = open[i] + 1;
        else
            open[i + 1] = open[i];
    }
    for (int i = total_length - 2; i >= 0; i--)
    {
        if (str[i] == ')')
            close[i] = close[i + 1] + 1;
        else
            close[i] = close[i + 1];
    }
    if (open[total_length] == 0)
        return total_length;
    if (close[0] == 0)
        return 0;
    for (int i = 0; i <= total_length; i++)
        if (open[i] == close[i])
            index = i;
    return index;
}
int main()
{
    string str = "))))(())";
    cout << "Index of equal point: " << findEqualPoint(str);
}