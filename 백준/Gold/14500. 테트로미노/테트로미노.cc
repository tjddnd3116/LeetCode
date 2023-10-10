#include <iostream>
#include <vector>

using namespace std;

// 0 1 2
// 3 4 5

// 4 / 3 -> 1
// 4 % 3 -> 2

vector<pair<int, int>> rowType = {{0, 1}, {0, 2}, {0, 5}, {1, 2}, {2, 3}, {2, 5}, {3, 4}, {3, 5}, {4, 5}};

vector<pair<int, int>> colType = {{0, 1}, {0, 2}, {0, 5}, {1, 2}, {2, 3}, {3, 4}, {3, 5}, {4, 5}};

int getRowSum(vector<vector<int>>& paper, int gridSum, pair<int, int>& rowType, int i, int j)
{
	int x1 = i + (rowType.first / 3);
	int y1 = j + (rowType.first % 3);

	int x2 = i + (rowType.second / 3);
	int y2 = j + (rowType.second % 3);

	return gridSum - paper[x1][y1] - paper[x2][y2];
}

int getColSum(vector<vector<int>>& paper, int gridSum, pair<int, int>& colType, int i, int j)
{

	int x1 = i + (colType.first % 3);
	int y1 = j + (colType.first / 3);

	int x2 = i + (colType.second % 3);
	int y2 = j + (colType.second / 3);

	return gridSum - paper[x1][y1] - paper[x2][y2];
}

int getRowVal(vector<vector<int>>& paper)
{
	int maxVal = 0;
	int gridSum = 0;

	for (int i = 0; i < (int)paper.size(); i++)
	{
		for (int j = 0; j < (int)paper[i].size() - 2; j++)
		{
			if (i < (int)paper.size() - 1)
			{
				gridSum = 0;
				gridSum += paper[i][j];
				gridSum += paper[i][j + 1];
				gridSum += paper[i][j + 2];
				gridSum += paper[i + 1][j];
				gridSum += paper[i + 1][j + 1];
				gridSum += paper[i + 1][j + 2];
				for (int k = 0; k < (int)rowType.size(); k++)
					maxVal = max(maxVal, getRowSum(paper, gridSum, rowType[k], i, j));
			}
			if (j < (int)paper[i].size() - 3)
				maxVal = max(maxVal, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3]);
		}
	}
	return maxVal;
}

int getColVal(vector<vector<int>>& paper)
{
	int maxVal = 0;
	int gridSum = 0;

	for (int i = 0; i < (int)paper.size() - 2; i++)
	{
		for (int j = 0; j < (int)paper[i].size(); j++)
		{
			if (j < (int)paper[i].size() - 1)
			{
				gridSum = 0;
				gridSum += paper[i][j];
				gridSum += paper[i][j + 1];
				gridSum += paper[i + 1][j];
				gridSum += paper[i + 1][j + 1];
				gridSum += paper[i + 2][j];
				gridSum += paper[i + 2][j + 1];
				for (int k = 0; k < (int)colType.size(); k++)
					maxVal = max(maxVal, getColSum(paper, gridSum, colType[k], i, j));
			}
			if (i < (int)paper.size() - 3)
				maxVal = max(maxVal, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j]);
		}
	}
	return maxVal;

}


int getMaxVal(vector<vector<int>>& paper)
{
	int rowVal = getRowVal(paper);
	int colVal = getColVal(paper);
	return max(rowVal, colVal);
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> paper(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	cout << getMaxVal(paper) << endl;
	return 0;
}