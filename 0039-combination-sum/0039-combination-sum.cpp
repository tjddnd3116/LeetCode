class Solution {
public:
    int getTmpVecSum(vector<int> &tmpVec)
    {
        int sum = 0;
        for (int i = 0; i < tmpVec.size(); i++)
            sum += tmpVec[i];
        return (sum);
            
    }
    void recurFindCom(vector<int>& candidates, int target, vector<vector<int>> &retVec, int idx, vector<int> &tmpVec)
    {
        int sum;
        
        if (idx == candidates.size())
            return;
        for (; idx < candidates.size(); idx++)
        {
            tmpVec.push_back(candidates[idx]);
            sum = getTmpVecSum(tmpVec);
            if (sum == target)
            {
                retVec.push_back(tmpVec);
                tmpVec.pop_back();
                return ;
            }
            else if (sum > target)
            {
                tmpVec.pop_back();
                return ;
            }
            recurFindCom(candidates, target, retVec, idx, tmpVec);
            tmpVec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> retVec;
        vector<int> tmpVec;
        sort(candidates.begin(), candidates.end());
       
        recurFindCom(candidates, target, retVec, 0, tmpVec);
        return (retVec);
    }
};;