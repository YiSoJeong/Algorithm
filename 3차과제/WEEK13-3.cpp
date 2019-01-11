#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int matrix[500][500] = { 0 };
bool vertex[500] = { false };
vector<string> str(1);

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
	}

	int s, e;
	string sj;
	for (int i = 1; i <= m; i++)
	{
		cin >> s >> e >> sj;
		matrix[s][e] = i;
		matrix[e][s] = i;
		str.push_back(sj);
	}

	int d;
	for (int i = 0; i < k; i++)
	{
		cin >> d;
		vertex[d] = false;
		for (int j = 0; j < 500; j++)
		{
			if (matrix[d][j] != 0)
			{
				str[matrix[d][j]] = "";
				matrix[d][j] = 0;
				matrix[j][d] = 0;
			}
		}
		for (auto i : str)
		{
			if (i != "")
				cout << i << " ";
		}
		cout <<"\n";

	}
	
	return 0;
}