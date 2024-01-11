#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;

    treeNode(int value)
    {
        data = value;
        left = right = NULL;
    }
};
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

    void level_order_traversal(TreeNode *root);
};
void TreeNode::level_order_traversal(TreeNode *root)
{
    vector<vector<int>> ans; // vector to store the level order traversal of binary tree
    if (root == NULL)
    {
        cout << "Root of tree don't exits";
        return;
    }
    queue<TreeNode *> q; // queue data structure used
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
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
    root->level_order_traversal(root);
}