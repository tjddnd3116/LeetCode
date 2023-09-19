#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> dir = {0, 1, 0, -1, 0};

string solution(int num, int target)
{
	queue<pair<string, int>> q;
	bool isVisit[10000] = {false, };

	q.push({"", num});
	isVisit[num] = true;

	while (q.size())
	{
		int size = q.size();
		while (size--)
		{
			pair<string, int> cur = q.front();
			q.pop();
			int d, s, l , r;
			d = cur.second * 2;
			d = (d > 9999 ? (d % 10000) : d);
			if (d == target)
				return cur.first + "D";
			if (!isVisit[d])
			{
				q.push({cur.first + "D", d});
				isVisit[d] = true;
			}
			s = cur.second == 0 ? 9999 : cur.second - 1;
			if (s == target)
				return cur.first + "S";
			if (!isVisit[s])
			{
				q.push({cur.first + "S", s});
				isVisit[s] = true;
			}
			l = ((cur.second % 1000) * 10) + (cur.second / 1000);
			if (l == target)
				return cur.first + "L";
			if (!isVisit[l])
			{
				q.push({cur.first + "L", l});
				isVisit[l] = true;
			}
			r = ((cur.second % 10) * 1000) + (cur.second / 10);
			if (r == target)
				return cur.first + "R";
			if (!isVisit[r])
			{
				q.push({cur.first + "R", r});
				isVisit[r] = true;
			}
		}
	}
	return "";
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << solution(a, b) << "\n";
	}
	return 0;
}