#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n,a;
	string str;
	stack<int> s;

	cin >> n;
	
	while (n--)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> a;
			s.push(a);
		}
		else if (str == "pop")
		{
			if (s.empty())
				cout << "-1\n";
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (str == "size")
		{
			cout << s.size() << "\n";
		}
		else if (str == "empty")
		{
			if (s.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "top")
		{
			if (s.empty())
				cout << "-1\n";
			else
				cout << s.top() << "\n";
		}
	}

	return 0;
}