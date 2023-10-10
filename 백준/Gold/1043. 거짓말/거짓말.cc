#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isContainTrueP(set<int>& trueP, vector<int> party)
{
	for (auto idx : party)
	{
		if (trueP.count(idx))
			return true;
	}
	return false;
}

int main(void)
{
	int n, m;
	int trueCnt;

	cin >> n >> m;
	cin >> trueCnt;
	set<int> trueP;
	vector<vector<int>> party(m);
	for (int i = 0; i < trueCnt; i++)
	{
		int idx;
		cin >> idx;
		trueP.insert(idx);
	}
	for (int i = 0; i < m; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			int idx;
			cin >> idx;
			party[i].push_back(idx);
		}
	}

	for (auto it = party.begin(); it != party.end();)
	{
		if (isContainTrueP(trueP, *it))
		{
			trueP.insert(it->begin(), it->end());
			party.erase(it);
			it = party.begin();
		}
		else
			it++;
	}
	cout << party.size() << endl;
}