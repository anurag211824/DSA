#include <iostream>
#include <malloc.h>

using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create_node(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  


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
        struct node *root = create_node(4);
        struct node *p1 = create_node(1);
        struct node *p2 = create_node(6);
        struct node *p3 = create_node(5);
        struct node *p4 = create_node(2);

        // linking of nodes together to form tree
       root->left=p1;
       root->right=p2;
       p1->left=p3;
       p1->right=p4;
       p2->left=NULL;
       p2->right=NULL;
       
       

       preorder(root);

        return 0;
    }