#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, a;
	string str;
	queue<int> q;

	cin >> n;

	while (n--)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> a;
			q.push(a);
		}
		else if (str == "pop")
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front")
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else if (str == "back")
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << "\n";
		}
	}

	return 0;
}