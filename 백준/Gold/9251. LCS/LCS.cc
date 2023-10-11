#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	string a, b;
	cin >> a >> b;

	vector<vector<int>> dp(a.size() +1, vector<int>(b.size() + 1, 0));

	for (int i = 0; i < (int)dp.size(); i++)
	{
		for (int j = 0; j < (int)dp[i].size(); j++)
		{
			if (i == 0 || j == 0)
				continue;
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp.back().back() << endl;
	return 0;
}