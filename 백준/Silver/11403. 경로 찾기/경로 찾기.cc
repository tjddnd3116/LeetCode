#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& visit, int i)
{
	for (auto& node : graph[i])
	{
		if (!visit[node])
		{
			visit[node] = 1;
			dfs(graph, visit, node);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>> graph(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			if (num)
				graph[i].push_back(j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		vector<int> visit(n, 0);
		dfs(graph, visit, i);
		for (auto& val : visit)
			cout << val << " ";
		cout << "\n";
	}

	return 0;
}