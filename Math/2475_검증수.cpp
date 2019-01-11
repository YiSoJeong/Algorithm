#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector<int> a(5);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		a[i] *= a[i];
		sum += a[i];
	}

	cout << sum % 10;

	return 0;
}