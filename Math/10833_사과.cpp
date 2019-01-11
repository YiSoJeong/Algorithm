#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int sum = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;

	cin >> n;

	int student, apple;

	for (int i = 0; i < n; i++)
	{
		cin >> student >> apple;
		sum += (apple % student);
	}

	cout << sum;

	return 0;
}