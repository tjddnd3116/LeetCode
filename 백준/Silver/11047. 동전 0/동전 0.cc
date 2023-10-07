#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinCoin(vector<int>& coin, int k)
{
	if (k == 0)
		return 0;
	auto low = lower_bound(coin.begin(), coin.end(), k);
	if (*low != k)
		low--;
	return getMinCoin(coin, k - (*low)) + 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> coin(n);
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	cout << getMinCoin(coin, k) << endl;
	return 0;
}