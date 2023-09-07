class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};

    bool dfs(vector<vector<char>>& board, string& word, int idx, int row, int col)
    {
        if (idx == word.size())
            return true;
        for (int i = 0; i < 4; i++)
        {
            int tmpRow = row + dir[i];
            int tmpCol = col + dir[i + 1];
            if (tmpRow < 0 || tmpRow >= board.size() || tmpCol < 0 || tmpCol >= board[tmpRow].size() || board[tmpRow][tmpCol] != word[idx])
                continue;
            char tmpChar = board[tmpRow][tmpCol];
            board[tmpRow][tmpCol] = '*';
            if (dfs(board, word, idx + 1, tmpRow, tmpCol))
                return true;
            board[tmpRow][tmpCol] = tmpChar;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    char tmpChar = board[i][j];
                    board[i][j] = '*';
                    if (dfs(board, word, 1, i, j))
                        return true;
                    board[i][j] = tmpChar;
                }
            }
        }
        return false;
    }
};