#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001][3] = { 0 };

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		dp[i][0] = r;
		dp[i][1] = g;
		dp[i][2] = b;
	}

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1] + dp[i][0], dp[i - 1][2] + dp[i][0]);
		dp[i][1] = min(dp[i - 1][0] + dp[i][1], dp[i - 1][2] + dp[i][1]);
		dp[i][2] = min(dp[i - 1][0] + dp[i][2], dp[i - 1][1] + dp[i][2]);
	}

	cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);

	return 0;
}