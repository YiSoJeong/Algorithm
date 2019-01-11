#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Meeting
{
	int start, end;
};

bool compare(Meeting u, Meeting v)
{
	if (u.end == v.end)					//������ �ð��� ������ �̸����� ��
		return u.start < v.start;
	else
		return u.end < v.end;			//�ƴϸ� ���� ������ ��
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	int ans = 0;

	cin >> n;

	vector<Meeting> a(n);

	int s, e;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		a[i].start = s;
		a[i].end = e;
	}

	sort(a.begin(), a.end(), compare);
	int now = 0;

	for (int i = 0; i < a.size(); i++)
	{
		if (now <= a[i].start)			//���۽ð��� ����ð����� �ĸ�
		{
			now = a[i].end;				//�����ð����� ����ð� ����
			ans++;
		}
	}

	cout << ans;

	return 0;
}