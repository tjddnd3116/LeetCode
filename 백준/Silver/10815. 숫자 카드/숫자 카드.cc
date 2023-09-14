#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> cardSet(N, 0);

	for (int i = 0; i < N; i++)
		cin >> cardSet[i];

	sort(cardSet.begin(), cardSet.end());

	int M;
	cin >> M;
	int card;
	for (int i = 0; i < M; i++)
	{
		cin >> card;
		cout << binary_search(cardSet.begin(), cardSet.end(), card) << " ";
	}
	return 0;
}