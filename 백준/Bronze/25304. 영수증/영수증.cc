#include <iostream>

using namespace std;

int main(void)
{
	int X, N;
	int sum = 0;
	cin >> X >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		sum += a * b;
	}
	cout << (sum == X ? "Yes" : "No") << endl;
}