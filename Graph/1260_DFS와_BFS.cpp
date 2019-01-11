#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

bool visit[1001] = {false};
vector<int> v[1001];

void dfs(int k)	//재귀
{
	cout << k << " ";
	visit[k] = true;
	for (auto i : v[k])
	{
		if (!visit[i])
			dfs(i);
	}
	/*for (int i = 0; i < v[k].size(); i++)
	{
		if (!visit[v[k][i]])
			dfs(v[k][i]);
	}*/
}

void bfs(int k)	//큐
{
	queue<int> q;
	q.push(k);
	visit[k] = true;

	while (!q.empty())
	{
		cout << q.front() << " ";
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
		/*for (int i = 0; i < v[par].size(); i++)
		{
			if (!visit[v[par][i]])
			{
				q.push(v[par][i]);
				visit[v[par][i]] = true;
			}
		}*/
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m, k;
	
	cin >> n >> m >> k;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());	//작은 번호 순서대로 돌기 위해서 정렬
	}

	dfs(k);
	memset(visit, 0, sizeof(visit)); // dfs돌고 나서 visit배열 초기화
	cout << "\n";
	bfs(k);


	return 0;
}