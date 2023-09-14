#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, k;
	vector<int> score;
	cin >> N >> k;


	for (int i = 0; i < N; i++)
	{
		int s;
		cin >> s;
		score.push_back(s);
	}
	sort(score.begin(), score.end(), greater<int>());
	cout << score[k - 1] << endl;
	return 0;
}