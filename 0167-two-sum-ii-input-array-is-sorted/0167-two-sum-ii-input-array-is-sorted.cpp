class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>::iterator startIt;
        vector<int>::iterator endIt;
        vector<int> retVec;
        
        startIt = numbers.begin();
        endIt = numbers.end() - 1;
        
        while (startIt <= endIt)
        {
            if (*startIt + *endIt == target)
                break;
            else if (*startIt + *endIt < target)
                startIt++;
            else if (*startIt + *endIt > target)
                endIt--;
        }
        retVec.push_back(startIt - numbers.begin() + 1);
        retVec.push_back(endIt - numbers.begin() + 1);
        return (retVec);
    }
};