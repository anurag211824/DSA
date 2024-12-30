#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int data, Node *next1, Node *prev1)
    {
        val = data;
        next = next1;
        prev = prev1;
    }
    Node(int data)
    {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

Node *arrayToDll(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *previous = head;
    head = head->next;
    head->prev = NULL;
    previous->next = NULL;
    delete previous;

    return head;
}
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->prev;
    newTail->next = NULL;
    tail->prev = NULL;
    delete tail;
    return head;
}
void printDLL(Node *head)
{
    Node *it = head;
    while (it)
    {
        cout << it->val << " ";
        it = it->next;
    }
    cout << endl;
}
Node *deleteKthNode(int k, Node *head)
{
    if (k <= 0 || head == NULL)
    {
        return head; // Return unchanged list for invalid k or empty list
    }

    int count = 0;
    Node *currNode = head;

    // Traverse to the k-th node
    while (currNode != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        currNode = currNode->next;
    }

    // If k is out of bounds, return the list unchanged
    if (currNode == NULL)
    {
        return head;
    }

    Node *prevNode = currNode->prev;
    Node *nextNode = currNode->next;

    if (prevNode == NULL && nextNode == NULL)
    {
        // If it's the only node in the list
        delete currNode;
        return NULL;
    }
    else if (prevNode == NULL)
    {
        // If it's the head node
        return deleteHead(head);
    }
    else if (nextNode == NULL)
    {
        // If it's the tail node
        return deleteTail(head);
    }

    // General case: deleting a node in the middle
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete currNode;

    return head;
}
void *deleteNode(Node *currNode)
{
    Node *prevNode = currNode->prev;
    Node *nextNode = currNode->next;

    if(nextNode==NULL){
        return deleteTail(currNode);
    }
      prevNode->next = nextNode;
    nextNode->prev = prevNode;
    currNode->next=currNode->prev=nullptr;
    delete currNode;


}

int main()
{
    vector<int> arr = {1, 3, 21, 5, 6, 7, 8, 78};
    Node *head = arrayToDll(arr);
    printDLL(head);
    // head = deleteHead(head);
    // printDLL(head);
    // head = deleteTail(head);
    // printDLL(head);
    // head = deleteKthNode(9, head);
    // printDLL(head);
    // deleteNode(head->next->next);
    // printDLL(head);
    return 0;
}
