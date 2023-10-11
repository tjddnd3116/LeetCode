#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<int>& nums, vector<int>& arr, int cnt, int idx)
{
	if (cnt == 0)
	{
		for (auto& num : arr)
			cout << num << " ";
		cout << "\n";
		return;
	}
	int last = 0;
	for (int i = idx; i < (int)nums.size(); i++)
	{
		if (nums[i] == last)
			continue;
		arr.push_back(nums[i]);
		last = nums[i];
		solution(nums, arr, cnt - 1, i);
		arr.pop_back();
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<int> nums(n);
	vector<int> arr;

	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	solution(nums, arr, m, 0);
	return 0;
}