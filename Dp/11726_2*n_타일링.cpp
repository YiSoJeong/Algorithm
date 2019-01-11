#include <iostream>
using namespace std;

int arr[1001] = {0};

int main()
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    arr[1] = 1;
    arr[2] = 2;

    for(int i=3;i<=n;i++)
    {
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;     //크기가 커져서 미리 나눠야 함
    }

    cout << arr[n];

    return 0;
}