#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool mySortFunc(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main(void)
{
	int n;
	int cnt = 1;
	cin >> n;
	vector<pair<int, int>> meeting(n);

	for (int i = 0; i < n; i++)
		cin >> meeting[i].first >> meeting[i].second;
	sort(meeting.begin(), meeting.end(), mySortFunc);

	int endTime = meeting[0].second;
	for (int i = 1; i < n; i++)
	{
		if (meeting[i].first >= endTime)
		{
			cnt++;
			endTime = meeting[i].second;
		}
	}
	cout << cnt << endl;
	return 0;
}