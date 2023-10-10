#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> triangle(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int num;
			cin >> num;
			triangle[i].push_back(num);
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < (int)triangle[i].size(); j++)
		{
			if (j == 0)
				triangle[i][j] += triangle[i - 1][j];
			else if (j == (int)triangle[i].size() - 1)
				triangle[i][j] += triangle[i - 1].back();
			else
				triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
		}
	}
	cout << *max_element(triangle.back().begin(), triangle.back().end());
	return 0;
}