#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    struct node *newnode;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            cout << "Duplicate element not inserted"<<endl;
            return;
        }
        else if (root->data < key)
            root = root->right;
        else
            root = root->left;
    }
    newnode = createnode(key);
    if (prev->data < key)
        prev->right = newnode;
    else
        prev->left = newnode;
}
int main()
{
    struct node *root = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    inOrder(root);
    cout << endl;
    insert(root, 23);
    inOrder(root);
    cout << endl;
    insert(root, 0);
    inOrder(root);
    cout << endl;
    insert(root, 3);
    inOrder(root);
}
