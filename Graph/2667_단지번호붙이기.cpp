#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
char m[25][25] = { NULL };
bool visit[25][25] = { false };
vector<int> danzi;

struct Node
{
	int y, x;
	Node(){}
	Node(int _y, int _x)
	{
		y = _y;
		x = _x;
	}
};

void bfs(int y, int x)
{
	queue<Node> q;
	int cnt = 1;	//처음 넣는거 세야함

	q.push({ y,x });
	visit[y][x] = true;
	

	int my[] = { 1,-1,0,0 };
	int mx[] = { 0,0,1,-1 };

	while (!q.empty())
	{
		Node cur = q.front();	//갱신 해야해서 while문 안에
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + my[i];
			int nx = cur.x + mx[i];

			if (m[ny][nx] == '1'&& ny >= 0 && nx >= 0 && ny < n && nx < n && !visit[ny][nx])
			{
				q.push({ ny,nx });
				cnt++;
				visit[ny][nx]=true;
			}

		}

	}

	danzi.push_back(cnt);
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
			if (!visit[i][j] && m[i][j] == '1')	//1일때만 bfs
				bfs(i, j);
		}
	}

	sort(danzi.begin(), danzi.end());

	cout << danzi.size() << "\n";
	
	for (auto i : danzi)
		cout << i << "\n";

	return 0;
}