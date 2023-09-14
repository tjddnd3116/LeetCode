#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	vector<int> copyArr(arr);
	sort(copyArr.begin(), copyArr.end());
	copyArr.erase(unique(copyArr.begin(), copyArr.end()), copyArr.end());
	for (auto& num : arr)
	{
		auto it = lower_bound(copyArr.begin(), copyArr.end(), num);
		cout << it - copyArr.begin() << " ";
	}
}