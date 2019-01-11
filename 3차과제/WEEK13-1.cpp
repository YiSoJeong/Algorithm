#include<cstdio>
#include<iostream>
using namespace std;

bool matrix[500][500] = { false };
bool vertex[500] = { false };
int v_cnt = 0;
int e_cnt = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		vertex[a] = true;
		v_cnt++;
	}


	int s, e;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		if (matrix[s][e] || matrix[e][s])
		{
			cout << "0\n";
		}
		else
		{
			matrix[s][e] = true;
			matrix[e][s] = true;
			e_cnt++;
		}
	}


	cout << v_cnt << " " << e_cnt;

	return 0;
}