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
    void dfs(TreeNode* root, vector<int>& nodeValues)
    {
        if (!root)
            return;
        if (root->left)
            dfs(root->left, nodeValues);
        nodeValues.push_back(root->val);
        if (root->right)
            dfs(root->right, nodeValues);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> nodeValues;
        int diff = INT_MAX;
        dfs(root, nodeValues);
        for (int i = 1; i < nodeValues.size(); i++)
            diff = min(diff, nodeValues[i] - nodeValues[i - 1]);
        return diff;
    }
};