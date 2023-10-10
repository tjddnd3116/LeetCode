#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;

	vector<int> arr(3, 0);
	vector<int> preMaxDp(3, 0);
	vector<int> curMaxDp(3, 0);
	vector<int> preMinDp(3, 0);
	vector<int> curMinDp(3, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[0] >> arr[1] >> arr[2];
		if (i == 0)
		{
			curMaxDp = arr;
			curMinDp = arr;
		}
		else
		{
			curMaxDp[0] = max(preMaxDp[0], preMaxDp[1]) + arr[0];
			curMaxDp[1] = *max_element(preMaxDp.begin(), preMaxDp.end()) + arr[1];
			curMaxDp[2] = max(preMaxDp[1], preMaxDp[2]) + arr[2];

			curMinDp[0] = min(preMinDp[0], preMinDp[1]) + arr[0];
			curMinDp[1] = *min_element(preMinDp.begin(), preMinDp.end()) + arr[1];
			curMinDp[2] = min(preMinDp[1], preMinDp[2]) + arr[2];
		}
		preMaxDp = curMaxDp;
		preMinDp = curMinDp;
	}
	cout << *max_element(preMaxDp.begin(), preMaxDp.end()) << " " <<
		*min_element(preMinDp.begin(), preMinDp.end());
	return 0;
}