#include <iostream>
#include <vector>

using namespace std;

int dp(int* memo, int n)
{
	if (memo[n] != 0)
		return memo[n];
	memo[n] = (dp(memo, n - 1) + dp(memo, n - 2) * 2) % 10007;
	return memo[n];
}

int main(void)
{
	int n;
	int memo[1001] = {0, };
	cin >> n;

	memo[1] = 1;
	memo[2] = 3;
	cout << dp(memo, n);
	return 0;
}