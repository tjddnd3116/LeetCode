#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<int> dir = {0, 1, 0, -1, 0};

int dfs(vector<string>& board, string& curWord, int x = 0, int y = 0)
{
	int cnt = 0;
	if (y == (int)board.size() - 1 && x == (int)board[y].size() - 1)
		return 1;
	curWord.push_back(board[y][x]);

	for (int i = 0; i < 4; i++)
	{
		int tmpY = y + dir[i];
		int tmpX = x + dir[i + 1];
		if (tmpY < 0 || tmpY >= (int)board.size() ||
				tmpX < 0 || tmpX >= (int)board[tmpY].size() ||
				curWord.find(board[tmpY][tmpX]) != string::npos)
			continue;
		cnt = max(cnt, dfs(board, curWord, tmpX, tmpY));
	}
	curWord.pop_back();
	return cnt + 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int r, c;
	cin >> r >> c;
	vector<string> board(r);
	for (int i = 0; i < r; i++)
		cin >> board[i];
	string curWord = "";
	cout << dfs(board, curWord);
	return 0;
}