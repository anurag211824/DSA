#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }

    void preorder_traversal(TreeNode *root);
};
void TreeNode::preorder_traversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode*> s;
    if (root == NULL)
        return;
    s.push(root);
    while (!s.empty())
    {
        for (int i = 0; i < s.size(); i++)
        {
            TreeNode *node = s.top();
            ans.push_back(node->data);
            s.pop();
            if (node->right != NULL) s.push(node->right);
            if (node->left != NULL) s.push(node->left);
                
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(0);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(6);

    /*    3
         / \
        2   4
       / \ / \
      8  7 5  6
     / \ / \
    2  0 7  6

    */
    root->preorder_traversal(root);
    // root,left,right
}