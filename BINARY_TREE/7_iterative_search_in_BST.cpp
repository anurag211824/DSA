#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
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
struct node *iterativeBSTsearch(struct node *root,int key){
    while(root!=NULL){
    if(root->data==key)
    return root;

    else if(root->data>key)
    root=root->left;

    else
    root=root->right;

    }

    return NULL;

}
int main(){
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
    cout<<endl;
    struct node *n = iterativeBSTsearch(root, 7);
    if (n == NULL)
        cout << "Element not found" << endl;
    else
    {
        cout << "element found:" << n->data << endl;
    }

    
}
