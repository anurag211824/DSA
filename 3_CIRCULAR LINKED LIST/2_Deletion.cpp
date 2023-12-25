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
// operation 4
struct node *deleteAthead(struct node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    else if (head->next == head)
    {
        free(head);
        return NULL; // return NULL as the list is now empty
    }
    struct node *ptr = head;
    struct node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    head = ptr->next;
    last->next = head;
    free(ptr);
    return head;
}
// operation 5
struct node *deleteAtend(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next->next != head)
    {
        ptr = ptr->next;
    }
    struct node *temp = ptr->next;
    ptr->next = head;
    free(temp);
    return head;
}
// operation 6
struct node *deleteAtk(struct node *head, int index)
{
    struct node *ptr1 = head;
    struct node *ptr2;
    int i = 0;
    while (i != index - 1)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
        i++;
    }
    ptr2->next = ptr1->next;
    free(ptr1);
    return head;
}
int main()
{
    struct node *head = (node *)(malloc(sizeof(node)));
    struct node *first = (node *)(malloc(sizeof(node)));
    struct node *second = (node *)(malloc(sizeof(node)));
    head->data = 1;
    first->data = 2;
    second->data = 3;
    head->next = first;
    first->next = second;
    second->next = head;
    display(head);
    head = insertAthead(head, 0);
    head = insertAtend(head, 4);
    display(head);
    head = deleteAthead(head);
    display(head);
    head = deleteAtend(head);
    display(head);
    head = insertAtend(head, 4);
    head = insertAtend(head, 5);
    head = insertAtend(head, 6);
    head = insertAtend(head, 7);
    display(head);
    head = deleteAtk(head, 5);
    display(head);
}
