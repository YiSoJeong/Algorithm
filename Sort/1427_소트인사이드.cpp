#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s;

	cin >> s;

	sort(s.begin(),s.end(),greater<int>());		// greater<int> : ��������

	cout << s;

	return 0;
}