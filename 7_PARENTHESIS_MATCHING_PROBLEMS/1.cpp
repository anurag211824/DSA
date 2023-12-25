#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    char *arr;
};
// operation 1
int isempty(struct stack *ptr)
{
    if (ptr->top <= -1)
        return 1;
    else
        return 0;
}
// operation 2
int isfull(struct stack *ptr)
{
    if (ptr->top >= ptr->size - 1)
        return 1;

    else
        return 0;
}
// operation 3
void showstack(struct stack *ptr)
{
    cout << "updated stack" << endl;
    if (ptr->top == -1)
        cout << "stack underflow no elements to display" << endl;

    for (int i = ptr->top; i >= 0; i--)
    {
        cout << ptr->arr[i] << endl;
    }
}
// operation 4
void push(struct stack *ptr, int value)
{
    if (isfull(ptr))
    {
        cout << "stack overflow !"
             << " can't push " << value << endl;
        return;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
// operation 5
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        cout << "stack underflow !"
             << "can't pop" << endl;
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int parenthesis_matching(string &exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(stack));
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    sp->top = -1;
    sp->size = exp.size();
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }

        else if (exp[i] == ')')
        {
            if (isempty(sp))
                return 0;
            else
            {
                pop(sp);
               
            }
        }
    }

    if (isempty(sp))
        return 1;
    else
        return 0;
}
int main()
{
    string exp = "(((3)))*(2-)(8+1)";
    // Check if stack is empty
    if ((parenthesis_matching(exp)))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    return 0;
}