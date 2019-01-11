#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool visit[101] = { false };
vector<int> v[101];

int bfs(int k)
{
	int cnt = 0;
	queue<int> q;
	q.push(k);
	visit[k] = true;

	while (!q.empty())
	{
		int par = q.front();
		q.pop();
		for (auto &i : v[par])
		{
			if (!visit[i])
			{
				cnt++;
				q.push(i);
				visit[i] = true;
			}
		}
	}

	return cnt;
}

int dfs(int k)
{
	int cnt = 0;
	visit[k] = true;
	for (auto i : v[k])
	{
		if (!visit[i])
		{
			cnt++;
			cnt += dfs(i);
		}
	}
	return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int com, edge;

	cin >> com >> edge;

	int a, b;
	for (int i = 0; i < edge; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cout << dfs(1);

	return 0;
}