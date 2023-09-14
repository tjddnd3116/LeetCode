#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void fillSpace(vector<string>& pattern, int rowStart, int rowEnd, int colStart, int colEnd)
{
	for (; rowStart < rowEnd; rowStart++)
	{
		for (int col = colStart; col < colEnd; col++)
			pattern[rowStart][col] = ' ';
	}
}

void recurSolution(vector<string>& pattern, int rowStart, int colStart, int len)
{
	if (len == 3)
	{
		pattern[rowStart + 1][colStart + 1] = ' ';
		return;
	}
	for (int row = 0; row < len; row += len / 3)
	{
		for (int col = 0; col < len; col += len / 3)
		{
			if (row == len / 3 && col == len / 3)
				fillSpace(pattern, rowStart + len / 3, rowStart + (len / 3) * 2, colStart + len / 3, colStart + (len / 3) * 2);
			else
				recurSolution(pattern, rowStart + row, colStart + col, len / 3);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> pattern(n, string(n, '*'));
	recurSolution(pattern, 0, 0, n);

	for (auto& row : pattern)
		cout << row << endl;

	return 0;
}