#include<cstdio>
#include<iostream>
using namespace std;

int price[11] = { 0 };

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, k;
	int cnt = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}

	while (k > 0)
	{
		for (int i = n - 1; i >= 0; i--)		//���ǹ����� ������ ������ ������ ���°�!!
		{
			//if (k / price[i] >= 1)				//0�̻��̸� ���ѷ���
			//{
			//	cnt += k / price[i];
			//	k -= (k / price[i]) * price[i];
			//}
			cnt += k / price[i];
			k %= price[i];							//����̱� ������ �������������� �ѹ��� ����
		}
	}

	cout << cnt;

	return 0;
}