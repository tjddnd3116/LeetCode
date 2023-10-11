#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int bfs(int start, int target)
{
	queue<long long> q;
	set<long long> numTable;
	int cnt = 0;

	q.push(start);
	numTable.insert(start);

	while (q.size())
	{
		int size = q.size();
		cnt++;
		while (size--)
		{
			long long curNum = q.front();
			q.pop();
			long long num1 = curNum * 2;
			long long num2 = (curNum * 10) + 1;
			if (num1 == target || num2 == target)
				return cnt + 1;
			if (num1 < target && !numTable.count(num1))
			{
				q.push(num1);
				numTable.insert(num1);
			}
			if (num2 < target && !numTable.count(num2))
			{
				q.push(num2);
				numTable.insert(num2);
			}
		}
	}
	return -1;
}

int main(void)
{
	int a, b;
	cin >> a >> b;
	cout << bfs(a, b);
	return 0;
}