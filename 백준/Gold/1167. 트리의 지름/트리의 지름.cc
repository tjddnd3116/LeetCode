#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vec = vector<vector<pair<int, int>>>;

int result = 0;
int endPoint = 0;

void dfs(vec& graph, vector<int>& isVisit, int node, int dis = 0)
{
	if (isVisit[node])
		return ;
	isVisit[node] = 1;
	if (result < dis)
	{
		result = dis;
		endPoint = node;
	}
	for (auto& g : graph[node])
		dfs(graph, isVisit, g.first, dis + g.second);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vec graph(n + 1);

	for (int i = 0; i < n; i++)
	{
		int idx;
		cin >> idx;
		while (1)
		{
			int node;
			cin >> node;
			if (node == -1)
				break;
			int dis;
			cin >> dis;
			graph[idx].push_back({node, dis});
		}
	}
	vector<int> isVisit(n + 1, 0);
	dfs(graph, isVisit, 1);
	result = 0;
	isVisit = vector<int>(n + 1, 0);
	dfs(graph, isVisit, endPoint);
	cout << result << endl;
	return 0;
}