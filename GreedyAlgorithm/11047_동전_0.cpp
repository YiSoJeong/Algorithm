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
		for (int i = n - 1; i >= 0; i--)		//조건문안의 조건이 만족할 때까지 도는거!!
		{
			//if (k / price[i] >= 1)				//0이상이면 무한루프
			//{
			//	cnt += k / price[i];
			//	k -= (k / price[i]) * price[i];
			//}
			cnt += k / price[i];
			k %= price[i];							//배수이기 때문에 나머지연산으로 한번에 가능
		}
	}

	cout << cnt;

	return 0;
}