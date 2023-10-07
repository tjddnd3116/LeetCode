#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	string s;
	int cnt = 0;
	cin >> n >> m >> s;

	for (int i = 0; i <= (int)s.size(); i++)
	{
		int k = 0;
		if (s[i] == 'O')
			continue;
		while (s[i + 1] == 'O' && s[i + 2] == 'I')
		{
			k++;
			if (k == n)
			{
				k--;
				cnt++;
			}
			i+=2;
		}
	}
	cout << cnt << endl;
	return 0;
}