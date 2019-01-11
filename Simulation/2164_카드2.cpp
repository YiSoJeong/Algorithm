#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    queue<int> q;
    int n;

    cin >> n;

    for(int i=1;i<=n;i++)
        q.push(i);

    while(q.size()!=1)
    {
        q.pop();            //팝하고 뒤로 이동
        q.push(q.front());
        q.pop();
    }

    cout << q.front();

    return 0;
}