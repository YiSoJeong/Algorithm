#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101010

class Maxheap
{
public:
    int arr[MAX] = {0};
    int idx = 1;                //size보다 1큰 수! [0]사용 안함

    bool empty()
    {
        return idx==1;
    }

    int size()
    {
        return idx-1;
    }

    void push(int a)
    {
        int cur = idx;
        arr[idx++] = a;

        while(cur>1)
        {
            if(arr[cur/2]<arr[cur])
                swap(arr[cur/2],arr[cur]);
            else
                break;
            cur /= 2;
        }
    }

    void pop()
    {
        if(empty()) return;
        arr[1]=arr[--idx];          //마지막 원소 있는 곳은 arr[idx-1] 그러므로 idx먼저 줄이고 대입
        int cur=1;
        int tmp;

        while(cur*2<idx)            //비교할 자식이 idx보다 작을 경우까지
        {
            tmp = cur;
            if(arr[cur*2]>arr[tmp]) //tmp랑 비교!!
                tmp = cur*2;
            if(cur*2+1<idx && arr[cur*2+1]>arr[tmp])
                tmp = cur*2+1;
            if(cur == tmp)
                break;
            swap(arr[tmp],arr[cur]);
            cur = tmp;
        }
    }

    int top()
    {
        if(idx == 1)
            arr[1] = 0;
        return arr[1];
    }

};

int main()
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    Maxheap h;

    cin >> N;

    for(int i=0;i<N;i++)
    {
        int a;
        cin >> a;

        if(a==0)
        {
            cout << h.top() << "\n";
            h.pop();
        }

        h.push(a);
    }

    return 0;
}