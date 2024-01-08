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
//operation 1
struct Node *InsertAtBegining(struct Node *head, int value)
{
    struct Node *newnode = (struct Node *)(malloc(sizeof(struct Node)));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return head;
}
//operation 2
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
//operation 3
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
//operation 4
struct Node*DeleteAtbegining(struct Node*head){
    if(head==NULL)
    cout<<"the  linked list is empty";
    struct Node*ptr=head;
    head=ptr->next;
    free(ptr);
    return head;
}
//operation 5
struct Node*DeleteAtk(struct Node*head,int index){
    struct Node*ptr1=head;
    struct Node*ptr2;
    int i=0;
    while(i!=index-1){
        ptr2=ptr1;
        ptr1=ptr1->next;
        i++;
    } 
    ptr2->next=ptr1->next;
    free(ptr1);
    return head;
}
//operation 6
struct Node*DeleteAtend(struct Node*head){
    struct Node*ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    struct Node*temp=ptr->next;
    ptr->next=NULL;
    free(temp);
    return head;
}
int main(){
    struct Node* head=NULL;
    head=InsertAtBegining(head,1);
    head = InsertAtEnd(head, 2);
    head = InsertAtEnd(head, 3);
    head = InsertAtEnd(head, 4);
    head = InsertAtEnd(head, 5);
    displayLinkedlist(head);
    head=DeleteAtk(head,4);
    displayLinkedlist(head);
    head=DeleteAtend(head);
    displayLinkedlist(head);
    
}