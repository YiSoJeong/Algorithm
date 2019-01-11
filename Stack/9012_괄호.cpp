#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;

	cin >> n;

	while (n--)
	{
		stack<char> st;
		string s;
		bool flag = false;
		cin >> s;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				st.push('(');

			else if (s[i] == ')')
			{
				if (!st.empty())
					st.pop();
				else
					flag = true;

			}
		}

		if (!st.empty() || flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}