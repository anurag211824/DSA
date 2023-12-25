#include<iostream>

using namespace std;
struct node{
    int data;
    struct node *next;
};
void displayLinkedList(struct node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL";
}

int main(){
   struct node *head;
   head=(struct node *)(malloc(sizeof(struct node)));
   head->data=1;
   struct node *first;
   first=(struct node *)(malloc(sizeof(struct node)));
   first->data=2;
   struct node *second;
   second=(struct node *)(malloc(sizeof(struct node)));
   second->data=3;
   struct node *third;
   third=(struct node *)(malloc(sizeof(struct node)));
   third->data=4;
   struct node *fourth;
   fourth=(struct node *)(malloc(sizeof(struct node)));
   fourth->data=5;
   head->next=first;
   first->next=second;
   second->next=third;
   third->next=fourth;
   fourth->next=NULL;
   displayLinkedList(head);

return 0;
}