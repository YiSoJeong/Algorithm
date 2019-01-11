#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

char arr[100][100] = { 0 };
bool visit[100][100] = { false };

struct Node
{
	int y, x, cnt;

	Node() {}
	Node(int _y, int _x, int _cnt)
	{
		y = _y;
		x = _x;
		cnt = _cnt;
	}
};

queue<Node> q;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	q.push({ 0,0,1 });
	visit[0][0] = true;

	int my[] = { 1,-1,0,0 };
	int mx[] = { 0,0,1,-1 };

	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + my[i];
			int nx = cur.x + mx[i];
			int nc = cur.cnt + 1;
			if (arr[ny][nx] == '1' && ny >= 0 && nx >= 0 && ny < n && nx < m && !visit[ny][nx])
			{
				if (ny == n - 1 && nx == m - 1)
				{
					cout << nc;
					return 0;
				}
				q.push({ ny,nx,nc });
				visit[ny][nx] = true;
			}
		}
	}

	return 0;
}