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
			if (arr[cur] < arr[cur / 2])		//자식이 작으므로 부모와 교체
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

		while (cur * 2 < idx)										//자식이 존재할 때 까지
		{
			tmp = cur;
			if (arr[cur * 2] < arr[tmp])							//왼쪽자식과 비교
				tmp = cur * 2;
			if (cur * 2 + 1 < idx && arr[cur * 2 + 1] < arr[tmp])	//오른쪽 자식이 존재 && 비교
				tmp = cur * 2 + 1;
			if (cur == tmp)											//자식보다 항상 작음
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