#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> pq;
	map<int, int> numTable;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num)
		{
			numTable[num]++;
			pq.push(abs(num));
		}
		else
		{
			if (pq.size())
			{
				int topNum = pq.top();
				pq.pop();
				if (numTable.count(-topNum) && numTable[-topNum] != 0)
				{
					cout << topNum * - 1 << "\n";
					numTable[-topNum]--;
				}
				else if (numTable.count(topNum) && numTable[topNum] != 0)
				{
					cout << topNum << "\n";
					numTable[topNum]--;
				}
			}
			else
				cout << 0 << "\n";
		}
	}
	return 0;
}