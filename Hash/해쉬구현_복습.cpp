#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int n,m;
int input[100] = { 0 };

int hashing(int a)
{
	return a % m;
}

void linearProbing()
{
	int hash_table[101] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int idx = hashing(input[i]);
		if (hash_table[idx] == 0)
			hash_table[idx] = input[i];
		else
		{
			while (hash_table[idx] != 0)
				idx++;
			hash_table[idx] = input[i];
		}
	}

	for (int i = 0; i < m; i++)
		cout << hash_table[i] << " ";
}

void quardraticProbing()
{
	int col = 0;
	int hash_table[101] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int idx = hashing(input[i]);
		int tmp = idx;
		if (hash_table == 0)
			hash_table[idx] = input[i];
		else
		{
			while (hash_table[tmp] != 0)
			{
				tmp = idx;
				col++;
				tmp += pow(col, 2);
				tmp %= m;				
			}
			hash_table[tmp] = input[i];
		}
	}

	for (int i = 0; i < m; i++)
		cout << hash_table[i] << " ";
}

void doubleHashing()
{
	int hash_table[101] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int idx = hashing(input[i]);
		int doubleHashing = 7 - input[i] % 7;
		if (hash_table[idx] == 0)
			hash_table[idx] = input[i];
		else
		{
			while (hash_table[idx] != 0)
			{
				idx += doubleHashing;
				idx %= m;
			}
			hash_table[idx] = input[i];
		}
	}

	for (int i = 0; i < m; i++)
		cout << hash_table[i] << " ";
}

void chaining()
{
	vector<int> hash_table[13];
	for (int i = 0; i < n; i++)
	{
		int idx = hashing(input[i]);
		hash_table[idx].push_back(input[i]);
	}

	for (int i = 0; i < m; i++)
	{
		cout << i << ": ";
		for (auto i : hash_table[i])
		{
			cout << i << " ";
		}
		cout << "\n";
	}

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	cout << "¼±Çü : ";
	linearProbing();
	cout << "\nÁ¦°ö : ";
	quardraticProbing();
	cout << "\n´õºí : ";
	doubleHashing();
	cout << "\nÃ¼ÀÌ´×\n";
	chaining();

	return 0;
}