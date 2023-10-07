#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int getYear(vector<int>& testCase)
{
	int max = lcm(testCase[0], testCase[1]);

	for (int i = testCase[2]; i <= max; i += testCase[0])
	{
		int y = i % testCase[1];
		if (y == 0)
			y = testCase[1];
		if (y == testCase[3])
			return i;
	}
	return -1;
}

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<int> testCase(4);
		cin >> testCase[0] >> testCase[1] >> testCase[2] >> testCase[3];
		cout << getYear(testCase) << endl;
	}
}