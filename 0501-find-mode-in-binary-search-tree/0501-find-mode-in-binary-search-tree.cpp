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
    void dfs(TreeNode* root, vector<int>& nodeVec)
    {
        if (!root)
            return;
        dfs(root->left, nodeVec);
        nodeVec.push_back(root->val);
        dfs(root->right, nodeVec);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> nodeVec;
        vector<int> ans;
        dfs(root, nodeVec);
        nodeVec.push_back(INT_MAX);
        int maxCnt = 0;
        int preNode = nodeVec[0];
        int cnt = 0;
        for (int i = 0; i < nodeVec.size(); i++)
        {
            if (nodeVec[i] == preNode)
                cnt++;
            else
            {
                if (cnt > maxCnt)
                {
                    maxCnt = cnt;
                    ans.clear();
                    ans.push_back(preNode);
                }
                else if (cnt == maxCnt)
                    ans.push_back(preNode);
                cnt = 1;
                preNode = nodeVec[i];
            }
        }
        return ans;
    }
};