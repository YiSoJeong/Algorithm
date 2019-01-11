#include<cstdio>
#include<iostream>
using namespace std;

int dp[12] = { 0 };

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int n,a;
	cin >> n;
	while (n--)
	{
		cin >> a;
		cout << dp[a] << "\n";
	}

	return 0;
}