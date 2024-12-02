#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int data, Node* next1, Node* prev1) {
        val = data;
        next = next1;
        prev = prev1;
    }
    Node(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

Node* arrayToDll(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node* head) {
    Node* it = head;
    cout << "Doubly Linked List Structure:\n";
    cout << "------------------------------------\n";
    while (it) {
        cout << "Current Node: " << it->val << "\n";

        if (it->prev) 
            cout << "  Previous Node: " << it->prev->val << "\n";
        else 
            cout << "  Previous Node: NULL\n";

        if (it->next) 
            cout << "  Next Node: " << it->next->val << "\n";
        else 
            cout << "  Next Node: NULL\n";

        cout << "------------------------------------\n";
        it = it->next;
    }
}

int main() {
    vector<int> arr = {1, 3, 21, 5, 6, 7};
    Node* head = arrayToDll(arr);
    printDLL(head);
    return 0;
}

