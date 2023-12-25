#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int *arr;
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
// operation 6
int peek(struct stack *ptr, int i)
{
    int arrindex = ptr->top - i + 1;
    if (arrindex < 0)
    {
        cout << "not valid for the stack";
        return -1;
    }
    else
    {
        cout << "peeked element:";
        return ptr->arr[arrindex];
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    ;
    s->size = 10;
    s->top = -1;
    s->arr = (int *)(malloc(s->size * sizeof(int)));
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    showstack(s);
    return 0;
}