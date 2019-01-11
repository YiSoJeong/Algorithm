#include<cstdio>
#include<iostream>
using namespace std;

long long fac(long long k)
{
	if (k == 0)
		return 1;
	else
		return k * fac(k - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	long long n, m;
	long long com;

	cin >> n >> m;

	com = fac(n) / fac(m);

	int ans = 1;
	while (com % 10 != 0)
	{
		com /= 10;
		ans++;
	}

	cout << ans;

	return 0;
}