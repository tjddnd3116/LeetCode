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
	int *cardSet = new int[N];

	for (int i = 0; i < N; i++)
		cin >> cardSet[i];

	sort(cardSet, cardSet + N);

	int M;
	cin >> M;
	int card;
	for (int i = 0; i < M; i++)
	{
		cin >> card;
		cout << binary_search(cardSet, cardSet + N, card) << " ";
	}
	return 0;
}