#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
// operation 1
int isempty()
{
    if (top == NULL)
        return 1;

    else
        return 0;
}
// operation 2
int isfull()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        return 1;

    else
        return 0;
}
// operation 3
void display()
{
    if (top == NULL)
        cout << "stack underflow" << endl;

    struct node *ptr = top;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
// operation 4
void push(int value)
{
    if (isfull())
        cout << "stack overflow" << endl;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}
// operation 5
void pop()
{
    if (isempty())
    {
        cout << "stack underflow" << endl;
    }
    else
    {
        struct node *temp = top;
        int value = temp->data;
        top = top->next;
        free(temp);
        cout << "the poped element is:" << value << endl;
    }
}
// operation 6
void peek(int pos)
{
    struct node *ptr = top;
    int i = 0;
    while (i != pos - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    if (ptr != NULL)
        cout << "the peeked element is:" << ptr->data << endl;
}
// operation 7
void stacktop()
{
    cout << "the stack top is:" << (top->data) << endl;
}
// operation 8
void stackbottom()
{
    struct node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    cout << "the stack bottom is:" << ptr->data << endl;
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    // pop();
    // pop();
    // display();
    // push(9);
    // push(12);
    // push(23);
    // push(34);
    // display();
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    //  pop();
    // pop();
    peek(1);
    peek(2);
    peek(3);
    stacktop();
    stackbottom();
    return 0;
}