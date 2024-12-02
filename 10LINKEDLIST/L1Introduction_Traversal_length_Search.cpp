#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

public:
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};
ListNode *arrToLinkedList(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *it = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *node = new ListNode(arr[i]);
        it->next = node;
        it = node;
    }
    return head;
}

void printLinkedList(ListNode *head)
{
    ListNode *it = head;
    while (it)
    {
        cout << it->val << " ";
        it = it->next;
    }
}
int LengthLinkedList(ListNode *head)
{
    ListNode *it = head;
    int len = 0;
    while (it)
    {
        len++;
        it = it->next;
    }
    return len;
}
ListNode *deleteHead(ListNode *head){
    if(head==NULL) return head;
    
    ListNode *temp=head;
    head=head->next;
      free(temp);
    return head;
}
ListNode *deleteTail(ListNode *head){
    if(head==NULL || head->next==NULL) return NULL;

    ListNode *it=head;
    while(it->next->next!=NULL){
        it=it->next;
    }
    ListNode *temp=it->next;
    it->next=NULL;
    free(temp);
    return head;
}
int main()
{
    vector<int> arr = {2, 3, 5, 6, 7, 4, 2, 9};
    ListNode *head = arrToLinkedList(arr);
    head=deleteHead(head);
    head=deleteTail(head);
    printLinkedList(head);
}