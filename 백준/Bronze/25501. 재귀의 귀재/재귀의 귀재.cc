#include <iostream>

using namespace std;

int recursion(string word, int& cnt)
{
	cnt++;
	if (word.size() <= 1)
		return 1;
	if (word.front() != word.back())
		return 0;
	return recursion(word.substr(1, word.size() - 2), cnt);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		int cnt = 0;
		int ans = recursion(word, cnt);
		cout << ans << " " << cnt << "\n";
	}
	return 0;
}