#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

bool visit[1001] = { false };
vector<int> v[1001];

bool bfs(int k)
{
	if (visit[k])
		return false;

	queue<int> q;
	q.push(k);
	visit[k] = true;

	while (!q.empty())
	{
		int par = q.front();
		q.pop();
		for (auto i : v[par])
		{
			if (!visit[i])
			{
				q.push(i);
				visit[i] = true;
			}
		}
	}

	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int a, b;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int link = 0;
	for (int i = 1; i <= n; i++)
	{
		if (bfs(i))
			link++;
	}

	cout << link;

	return 0;
}