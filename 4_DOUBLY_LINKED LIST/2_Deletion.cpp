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
    {    if (ptr == NULL) {
            cout << "Index out of bounds." << endl;
            return head;
        }
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

    return head;
}
//operation 4
struct node *deleteAthead(struct node *head){
    struct node *ptr=head;
   if(head==NULL){
    cout<<"empty list";
     return NULL;
   }
   else if(head->next==NULL){
    free(head);
    return NULL;
   }
    head=ptr->next;
    head->prev=NULL;
    free(ptr);
    return head;
}
//operation 5
struct node *deleteAtend(struct node *head){
      struct node *ptr=head;
      while(ptr->next->next!=NULL){
        ptr=ptr->next;
      }
      struct node *temp=ptr->next;
      ptr->next=NULL;
      free(temp);
      return head;
}
//operation 6
struct node *deleteAtk(struct node *head,int index){
    struct node *ptr1=head;
    struct node *ptr2;
    int i=0;
    while(i!=index-1){
        ptr2=ptr1;
        ptr1=ptr1->next;
        i++;
    }
    ptr2->next=ptr1->next;
    if(ptr1->next!=NULL){
        ptr1->next->prev=ptr2;
    }
    free(ptr1);
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
    head=deleteAthead(head);
    displayforward(head);
    head=deleteAtend(head);
    displayforward(head);
    head=deleteAtk(head,3);
     displayforward(head);
    return 0;
}