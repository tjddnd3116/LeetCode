#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>& arr, vector<int>& curArr, int m, int curIdx)
{
	if (m == 0)
	{
		for (auto& num : curArr)
			cout << num << " ";
		cout << "\n";
		return;
	}
	for (int i = curIdx; i < (int)arr.size(); i++)
	{
		curArr.push_back(arr[i]);
		dfs(arr, curArr, m - 1, i);
		curArr.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> arr(n, 0);
	vector<int> curArr;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	dfs(arr, curArr, m, 0);
	return 0;
}