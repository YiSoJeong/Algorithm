
#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

int n;
int RGB_cnt = 0;
int RG_cnt = 0;
char m[100][100] = { NULL };
bool RGB_visit[100][100] = { false };
bool RG_visit[100][100] = { false };

struct Node
{
	int y, x;
	char c;
	Node(){}
	Node(int _y, int _x, char _c)
	{
		y = _y;
		x = _x;
		c = _c;
	}
};

void RGB_bfs(int y, int x,char c)
{
	queue<Node> q;

	q.push({ y,x,c });
	RGB_visit[y][x] = true;

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
			char nc = cur.c;

			if (m[ny][nx] == nc && ny >= 0 && nx >= 0 && ny < n &&nx < n && !RGB_visit[ny][nx])
			{
				q.push({ ny,nx,nc });
				RGB_visit[ny][nx] = true;
			}
		}
	}

	return;
}

void RG_bfs(int y, int x, char c)
{
	queue<Node> q;

	q.push({ y,x,c });
	RG_visit[y][x] = true;

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
			char nc = cur.c;

			if (nc == 'R' || nc == 'G')
			{
				if ((m[ny][nx] == 'R' || m[ny][nx] == 'G') && ny >= 0 && nx >= 0 && ny < n && nx < n && !RG_visit[ny][nx])
				{
					q.push({ ny,nx,nc });
					RG_visit[ny][nx] = true;
				}
			}
			else
			{
				if (m[ny][nx] == nc && ny >= 0 && nx >= 0 && ny < n &&nx < n && !RG_visit[ny][nx])
				{
					q.push({ ny,nx,nc });
					RG_visit[ny][nx] = true;
				}
			}
		}
	}

	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!RG_visit[i][j])
			{
				RG_bfs(i, j, m[i][j]);
				RG_cnt++;
			}
			if (!RGB_visit[i][j])
			{
				RGB_bfs(i, j, m[i][j]);
				RGB_cnt++;
			}
		}
	}

	cout << RGB_cnt << " " << RG_cnt;

	return 0;
}