#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};
//      4
//     / \
//    1   6
//   / \
//  5   2

// Preorder traversal: Root → Left → Right
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = new Node(4);
    Node* p1 = new Node(1);
    Node* p2 = new Node(6);
    Node* p3 = new Node(5);
    Node* p4 = new Node(2);

    // Linking of nodes together to form tree
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = NULL;
    p2->right = NULL;

    preorder(root);

    return 0;
}
