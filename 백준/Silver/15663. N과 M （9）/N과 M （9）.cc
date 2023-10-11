#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<int>& nums, vector<int>& arr,  vector<int>& isVisit, int cnt)
{
	if (cnt == 0)
	{
		for (auto& num : arr)
			cout << num << " ";
		cout << "\n";
		return;
	}
	int last = 0;
	for (int i = 0; i < (int)nums.size(); i++)
	{
		if (isVisit[i] || nums[i] == last)
			continue;
		isVisit[i] = 1;
		arr.push_back(nums[i]);
		last = nums[i];
		solution(nums, arr, isVisit, cnt - 1);
		arr.pop_back();
		isVisit[i] = 0;
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<int> nums(n);
	vector<int> isVisit(n, 0);
	vector<int> arr;

	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	solution(nums, arr, isVisit, m);
	return 0;
}