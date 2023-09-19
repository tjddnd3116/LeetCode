#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void fillSpace(string& str, int start, int end)
{
	for (; start < end; start++)
		str[start] = ' ';
}

void changeStr(string& str, int start, int end)
{
	if (end - start == 1)
		return;

	int len = (end - start) / 3;
	changeStr(str, start, start + len);
	fillSpace(str, start + len, start + len * 2);
	changeStr(str, start + len * 2, end);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		int n = 0;
		cin >> n;
		if (cin.eof())
			return 0;

		string str(pow(3, n), '-');
		changeStr(str, 0, str.size());
		cout << str << endl;
	}
	return 0;
}