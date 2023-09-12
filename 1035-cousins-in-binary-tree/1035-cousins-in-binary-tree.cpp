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
    bool getNode(TreeNode* root, int x, pair<int, int>& node, int depth)
    {
        if (!root)
            return false;
        if ((root->left && root->left->val == x) || (root->right && root->right->val == x))
        {
            node.first = root->val;
            node.second = depth + 1;
            return true;
        }
        return getNode(root->left, x, node, depth + 1) || getNode(root->right, x, node, depth + 1);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y)
            return false;

        pair<int, int> xNode;
        pair<int, int> yNode;

        getNode(root, x, xNode, 0);
        getNode(root, y, yNode, 0);
        
        if (xNode.first != yNode.first && xNode.second == yNode.second)
            return true;
        return false;
    }
};