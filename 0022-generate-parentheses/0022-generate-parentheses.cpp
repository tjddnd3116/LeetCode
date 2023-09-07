class Solution {
public:
    void recurSolution(int n, vector<string>& answer, string curString = "", int leftCnt = 0, int rightCnt = 0)
    {
        if (rightCnt > leftCnt)
            return;
        if (n == 0)
        {
            if (leftCnt == rightCnt)
                answer.push_back(curString);
            return;
        }
        recurSolution(n - 1, answer, curString + "(", leftCnt + 1, rightCnt);
        recurSolution(n - 1, answer, curString + ")", leftCnt, rightCnt + 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        recurSolution(n * 2, answer);
        return answer;
    }
};