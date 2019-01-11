#include<cstdio>
#include<iostream>
using namespace std;

bool vertex[500] = { false };
bool matrix[500][500] = { false };
int v = 0;
int edge = 0;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m, k;

	cin >> n >> m >> k;

	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		vertex[a] = true;
		v++;
	}

	int s, e;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		matrix[s][e] = true;
		matrix[e][s] = true;
		edge++;
	}

	int d;
	for (int i = 0; i < k; i++)
	{
		cin >> d;
		if (!vertex[d])
			cout << "-1\n";
		else
		{
			vertex[d] = false;
			int cnt = 0;
			for (int j = 0; j < 500; j++)
			{
				if (matrix[d][j])
				{
					cnt++;
					matrix[d][j] = false;
					matrix[j][d] = false;
				}
			}
			v--;
			edge -= cnt;
			cout << v << " " << edge << "\n";
		}
	}

	return 0;
}