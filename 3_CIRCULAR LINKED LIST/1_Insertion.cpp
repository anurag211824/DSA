#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
// traversal of circular linked list
void display(struct node *head)
{
    struct node *ptr = head;
    do
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    } while (ptr != head);
    cout << "head" << endl;
}
// operation 1
struct node *insertAthead(struct node *head, int value)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    if (head == NULL)
    {
        newnode->data = value;
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        newnode->data = value;
        newnode->next = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        head = newnode;
    }
    return head;
}
// operation 2
struct node *insertAtend(struct node *head, int value)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    struct node *ptr = head;
    if (head == NULL)
    {
        newnode->data = value;
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        newnode->data = value;
        ptr->next = newnode;
        newnode->next = head;
    }
    return head;
}
// operation 3
struct node *insertAtk(struct node *head, int value, int index)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    struct node *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    newnode->data = value;
    newnode->next = ptr->next;
    ptr->next = newnode;
    return head;
}

int main()
{
    struct node *head = NULL;
    head = insertAthead(head, 1);
    head = insertAtend(head, 2);
    head = insertAthead(head, 3);
    head = insertAtend(head, 4);
    head = insertAthead(head, 5);
    head = insertAtend(head, 0);
   
    display(head);
    head = insertAtk(head, 21, 6);
    head=insertAtend(head,21);
    display(head);
}