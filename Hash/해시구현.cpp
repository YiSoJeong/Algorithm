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
	if (hash_table[hashed] == 0)			//빈공간이면 입력
		hash_table[hashed] = data;
	else									//이미 있으면 한칸씩 뒤로 검사
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
	if (hash_table[hashed] == 0)			//해쉬자리에 수 없으면 입력
		hash_table[hashed] = data;
	else									//이미 있을 경우
	{
		while (hash_table[tmp] != 0)		//빈공간 찾을때까지
		{
			tmp = hashed;
			cnt++;							//몇번 충돌했는지
			tmp += pow(cnt, 2);				//기존 해쉬에 충돌^2 만큼 뒤로
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

	if (hash_table[first_hashed] == 0)						//첫해쉬 자리검사
		hash_table[first_hashed] = data;
	else if (hash_table[first_hashed + second_hashed] == 0)	//두번째해쉬 자리검사
		hash_table[first_hashed + second_hashed] = data;
	else
	{
		tmp = first_hashed + second_hashed;
		while (hash_table[tmp] != 0)						//빈공간 찾을 때까지
		{
			tmp += second_hashed;							//첫번째 해쉬 + 두번쩨 헤쉬 + 두번쩨 해쉬 +... 검사
			tmp %= m;
		}
		hash_table[tmp] = data;
	}
}

void chaining(int data)
{
	int first_hashed = data % m;
	chain[first_hashed].push_back(data);					//해쉬된 수뒤에 data연속으로 추가
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

	for (int i = 0; i < m; i++)					//출력
	{
		if (hash_table[i] != 0)
			cout << hash_table[i] << " ";
		else
			cout << "0 ";
	}

	/*for (int i = 0; i < m; i++)				//체이닝 출력
	{
		cout << i << ": ";
		for (auto &j : chain[i])
			cout << j << " ";
		cout << "\n";
	}*/

	return 0;
}