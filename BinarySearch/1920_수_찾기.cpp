#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[101010] = { 0 };

bool binary_search(int data)
{
	int front = 0;
	int end = n - 1;
	while (front <= end)				//front == end 일때 data랑 같은지 확인 필요
	{
		int mid = (end + front) / 2;

		if (arr[mid] == data)
		{
			return true;
		}
		else if (arr[mid] < data)		//else로 묶는 습관 중요
		{
			front = mid + 1;
		}
		else if (arr[mid] > data)
		{
			end = mid - 1;
		}
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int m;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
	}

	sort(arr, arr + n);
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		if (binary_search(a))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}