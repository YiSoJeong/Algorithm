#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string s;
stack<char> st;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> s;

	int ans = 0;
	int stick = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			st.push(s[i]);
			stick++;
		}
		else if (s[i] == ')')
		{
			stick--;

			if (s[i - 1] == '(')
			{
				ans += stick;
			}
			else if (s[i - 1] == ')')
			{
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}