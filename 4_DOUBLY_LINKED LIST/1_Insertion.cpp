#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void displayforward(struct node *head)
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }

    cout << "NULL<-";
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL";
    cout << endl;
}
void displaybackward(struct node *head)
{
    struct node *ptr = head;
    cout << "NULL<-";
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->prev;
    }
    cout << "NULL";
    cout << endl;
}
// operation 1
struct node *insertAthead(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    return head;
}
// operation 2
struct node *insertAtend(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    if (head == NULL)
    {
        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = ptr;
        newnode->next = NULL;
        ptr->next = newnode;
    }
    return head;
}
// operation 3
struct node *insertAtk(struct node *head, int value, int index)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    newnode->data = value;
    newnode->prev = ptr;
    newnode->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->prev = newnode; // Set the prev of the next node to newnode
    }
    ptr->next = newnode; // Set the next of ptr to newnode
    ptr->next = newnode;

    return head;
}
int main()
{

    struct node *head = NULL;
    head = insertAthead(head, 1);
    head = insertAthead(head, 0);
    head = insertAtend(head, 2);
    head = insertAtend(head, 3);
    head = insertAtend(head, 4);
    head = insertAtend(head, 5);
    displayforward(head);
    displaybackward(head);
    // struct node *head = (struct node *)malloc(sizeof(struct node));
    // struct node *second = (struct node *)malloc(sizeof(struct node));
    // struct node *third = (struct node *)malloc(sizeof(struct node));
    // struct node *fourth = (struct node *)malloc(sizeof(struct node));
    // struct node *fifth = (struct node *)malloc(sizeof(struct node));
    // head->data = 1;
    // second->data = 2;
    // third->data = 3;
    // fourth->data = 4;
    // fifth->data = 5;
    // head->prev = NULL;
    // head->next = second;
    // second->prev = head;
    // second->next = third;
    // third->prev = second;
    // third->next = fourth;
    // fourth->prev = third;
    // fourth->next = fifth;
    // fifth->prev = fourth;
    // fifth->next = NULL;
    // displayforward(head);
    // displaybackward(head);
    // head = insertAthead(head, 12);
    // displayforward(head);
    // head = insertAtend(head, 99);
    // displayforward(head);
    // head=insertAtk(head,76,3);
    // displayforward(head);
    // displaybackward(head);

    return 0;
}