#include<iostream>
using namespace std;

#define MAX 1000001
int arr[MAX] = { 0 };

class MinHeap
{
public:
	int idx = 1;

	bool empty()
	{
		return { idx == 1 };
	}

	int size()
	{
		return { idx - 1 };
	}

	int top()
	{
		if (size() == 0)
		{
			arr[1] = 0;
		}
		return arr[1];
	}

	void push(int a)
	{
		int cur = idx;
		arr[idx++] = a;
		
		while (cur > 1)
		{
			if (arr[cur] < arr[cur / 2])		//�ڽ��� �����Ƿ� �θ�� ��ü
				swap(arr[cur], arr[cur / 2]);
			else break;
			cur /= 2;
		}
	}

	void pop()
	{
		if (empty())
			return;
		arr[1] = arr[--idx];
		int tmp;
		int cur = 1;

		while (cur * 2 < idx)										//�ڽ��� ������ �� ����
		{
			tmp = cur;
			if (arr[cur * 2] < arr[tmp])							//�����ڽİ� ��
				tmp = cur * 2;
			if (cur * 2 + 1 < idx && arr[cur * 2 + 1] < arr[tmp])	//������ �ڽ��� ���� && ��
				tmp = cur * 2 + 1;
			if (cur == tmp)											//�ڽĺ��� �׻� ����
				break;
			swap(arr[cur], arr[tmp]);
			cur = tmp;
		}
	}
};

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	MinHeap h;

	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		h.push(a);	
	}

	for (int i = 0; i < n; i++)
	{
		cout << h.top() << "\n";
		h.pop();
	}

	return 0;
}