#include <iostream>
#include <cstdlib>

using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
// traversal of linked list
void displayLinkedlist(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL";
    cout << endl;
}
// case 1
struct Node *InsertAtBegining(struct Node *head, int value)
{
    struct Node *newnode = (struct Node *)(malloc(sizeof(struct Node)));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return head;
}
// case 2
struct Node *InsertAtK(Node *head, int value, int index)
{    
    struct Node *newnode = (struct Node *)(malloc(sizeof(struct Node)));
    Node *ptr = head;
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
// case 3
struct Node *InsertAtEnd(struct Node *head, int value)
{
    struct Node *newnode = (struct Node *)(malloc(sizeof(struct Node)));
    Node *ptr = head;
    if (head == NULL)
    {
        head = newnode;
        newnode->data = value; // If the list is empty, make the new node the head
        newnode->next = NULL;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode->data = value;
        ptr->next = newnode;
        newnode->next = NULL;
    }
    return head;
}

int main()
{
    cout << "linked list before insertion:"<<endl;
    struct Node *head = (Node *)(malloc(sizeof(Node)));
    struct Node *first = (Node *)(malloc(sizeof(Node)));
    struct Node *second = (Node *)(malloc(sizeof(Node)));
    first->data = 2;
    head->data = 1;
    second->data = 3;
    head->next = first;
    first->next = second;
    second->next = NULL;
    displayLinkedlist(head);

    cout << "linked list after insertion:"<<endl;
    head = InsertAtBegining(head, 1);
    head = InsertAtEnd(head, 2);
    head = InsertAtEnd(head, 3);
    head = InsertAtEnd(head, 4);
    head = InsertAtEnd(head, 5);
    head = InsertAtK(head, 8,8);
    head=InsertAtEnd(head,10);
    //head=InsertAtK(head,11,1);
    displayLinkedlist(head);
    return 0;
}
