#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;
	vector<int> status(n, 0);
	deque<int> dq;

	for (int i = 0; i < n; i++)
		cin >> status[i];
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (status[i] == 0)
			dq.push_back(num);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		dq.push_front(num);
		cout << dq.back() << " ";
		dq.pop_back();
	}
}