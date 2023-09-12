/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void changeBST(TreeNode* root, int& val)
    {
        if (!root)
            return ;
        changeBST(root->right, val);
        val += root->val;
        root->val = val;
        changeBST(root->left, val);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int val = 0;
        changeBST(root, val);
        return root;
    }
};