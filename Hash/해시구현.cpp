#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int m;
int hash_table[101] = { 0 };
vector<int> chain[101];

void linearProbing(int data)
{
	int hashed = data % m;					
	if (hash_table[hashed] == 0)			//������̸� �Է�
		hash_table[hashed] = data;
	else									//�̹� ������ ��ĭ�� �ڷ� �˻�
	{
		while (hash_table[hashed] != 0)
		{
			hashed++;
		}
		hash_table[hashed] = data;
	}
}

void quardraticProbing(int data)
{
	int cnt = 0;
	int hashed = data % m;
	int tmp = hashed;
	if (hash_table[hashed] == 0)			//�ؽ��ڸ��� �� ������ �Է�
		hash_table[hashed] = data;
	else									//�̹� ���� ���
	{
		while (hash_table[tmp] != 0)		//����� ã��������
		{
			tmp = hashed;
			cnt++;							//��� �浹�ߴ���
			tmp += pow(cnt, 2);				//���� �ؽ��� �浹^2 ��ŭ �ڷ�
			tmp %= m;
		}
		hash_table[tmp] = data;
	}
}

void doubleHashing(int data)
{
	int tmp;
	int first_hashed = data % m;
	int second_hashed = 7 - (data % 7);

	if (hash_table[first_hashed] == 0)						//ù�ؽ� �ڸ��˻�
		hash_table[first_hashed] = data;
	else if (hash_table[first_hashed + second_hashed] == 0)	//�ι�°�ؽ� �ڸ��˻�
		hash_table[first_hashed + second_hashed] = data;
	else
	{
		tmp = first_hashed + second_hashed;
		while (hash_table[tmp] != 0)						//����� ã�� ������
		{
			tmp += second_hashed;							//ù��° �ؽ� + �ι��� �콬 + �ι��� �ؽ� +... �˻�
			tmp %= m;
		}
		hash_table[tmp] = data;
	}
}

void chaining(int data)
{
	int first_hashed = data % m;
	chain[first_hashed].push_back(data);					//�ؽ��� ���ڿ� data�������� �߰�
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		linearProbing(data);
		//quardraticProbing(data);
		//doubleHashing(data);
		//chaining(data);
	}

	for (int i = 0; i < m; i++)					//���
	{
		if (hash_table[i] != 0)
			cout << hash_table[i] << " ";
		else
			cout << "0 ";
	}

	/*for (int i = 0; i < m; i++)				//ü�̴� ���
	{
		cout << i << ": ";
		for (auto &j : chain[i])
			cout << j << " ";
		cout << "\n";
	}*/

	return 0;
}