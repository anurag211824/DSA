#include <iostream>
#include <malloc.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *Create_left_node(struct node *root, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    root->left = newnode;
    return newnode;
}

struct node *Create_right_node(struct node *root, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    root->right = newnode;
    return newnode;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        struct node *n = root;
        cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }
}

int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;

    struct node *l1 = Create_left_node(root, 3);
    struct node *r1 = Create_right_node(root, 2);

    struct node *l2 = Create_left_node(l1, 4);
    struct node *r2 = Create_right_node(l1, 5);

    struct node *l3 = Create_left_node(r1, 4);
    struct node *r3 = Create_right_node(r1, 5);

    struct node *l4 = Create_left_node(l2, 9);
    struct node *r4 = Create_right_node(l2, 6);

    preorder(root);

    return 0;
}
