#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int k;
		cin >> k;
		multiset<int> q;
		for (int j = 0; j < k; j++)
		{
			char c;
			int num;
			cin >> c >> num;
			if (c == 'I')
				q.insert(num);
			else if (c == 'D' && q.size())
			{
				if (num == 1)
					q.erase(--q.end());
				else
					q.erase(q.begin());
			}
		}
		if (q.empty())
			cout << "EMPTY" << endl;
		else
			cout << *(--q.end()) << " " << *q.begin() << endl;
	}
	return 0;
}