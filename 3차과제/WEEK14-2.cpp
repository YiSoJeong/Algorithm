#include<cstdio>
#include<iostream>
using namespace std;

bool edge[1001] = { false };
int matrix[501][501] = { 0 };
bool vertex[501] = { false };
bool visit[501] = { false };

void dfs(int idx)
{
	visit[idx] = true;
	for (int i = 1; i <= 500; i++)
	{
		if (matrix[idx][i]!=-1)
		{
			if (!visit[i])
			{
				edge[matrix[idx][i]] = true;
				//visit[i] = true;
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

	int n,m,k;

	//m이 간선의 개수

	cin >> n >> m >> k;
	
	//정점번호 -> 1번부터
	for (int i = 1; i <= 500; i++)
	{
		for (int j = 1; j <= 500; j++)
		{
			matrix[i][j] = -1;
		}
	}

	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		vertex[a] = true;
	}

	int s, e;
	for (int i = 0; i < m;i++)
	{
		cin >> s >> e;
		matrix[s][e] = i;
		matrix[e][s] = i;
	}

	dfs(k);

	for (int i = 0; i < m; i++)
	{
		if (edge[i])
			cout << i << " ";
	}
	cout << "\n";
	for (int i = 0; i < m; i++)
	{
		if (!edge[i])
			cout << i << " ";
	}

	return 0;
}