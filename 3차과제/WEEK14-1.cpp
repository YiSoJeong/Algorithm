#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n, m, start;
char vertex[500] = { NULL };
bool visit[500] = { false };
bool edge[500][500] = { false };

void dfs(int idx)
{
	//방문된 정점이 아닌경우 출력하고 체크
	if (!visit[idx])
	{
		cout << vertex[idx];
		visit[idx] = true;
	}

	//작은 수가 우선순위
	for (int i = 0; i < 500; i++)
	{
		//연결되어 있고 방문이 안되어 있으면 dfs재귀
		if (edge[idx][i] && edge[i][idx])
		{
			if (!visit[i])
			{
				dfs(i);
			}

		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);


	cin >> n >> m >> start;


	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cin >> vertex[a];
	}


	int s, e;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		edge[s][e] = true;
		edge[e][s] = true;
	}

	dfs(start);

	return 0;
}