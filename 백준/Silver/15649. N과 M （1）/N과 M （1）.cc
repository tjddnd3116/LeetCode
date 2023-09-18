#include <iostream>
#include <vector>

using namespace std;

void recurPrint(vector<int>& isVisit, vector<int>& arr, int n, int m)
{
	if (m == 0)
	{
		for (auto& e : arr)
			cout << e << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isVisit[i])
			continue;
		isVisit[i] = 1;
		arr.push_back(i + 1);
		recurPrint(isVisit, arr, n, m - 1);
		isVisit[i] =0;
		arr.pop_back();
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> isVisit(n, 0);
	vector<int> arr;

	recurPrint(isVisit, arr, n, m);
	return 0;
}