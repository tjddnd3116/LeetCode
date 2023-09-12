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
    int dfs(TreeNode* root, int& maxDiameter)
    {
        if (!root)
            return 0;
        int leftLen = dfs(root->left, maxDiameter);
        int rightLen = dfs(root->right, maxDiameter);
        maxDiameter = max(maxDiameter, leftLen + rightLen);
        return max(leftLen, rightLen) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        dfs(root, maxDiameter);
        return maxDiameter;
    }
};