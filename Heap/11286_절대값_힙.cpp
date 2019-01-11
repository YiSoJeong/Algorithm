#include <iostream>
using namespace std;

#define MAX 101010

class absHeap
{
public:
    int arr[MAX] = {0};
    int idx = 1;

    bool empty()
    {
        return idx == 1;
    }

    int size()
    {
        return idx-1;
    }

    void push(int a)        //최소힙 - 부모가 더 크면 swap
    {                       //절대값 같을 경우 작은 수 push
        int cur = idx;
        arr[idx++] = a;

        while(cur>1)
        {
            if(abs[])
            if(abs(arr[cur/2])>abs(arr[cur]))
                swap(arr[cur/2],arr[cur]);
            else
                break;
            cur /= 2;
        }
    }

    void pop()              //최소힙 - 자식이 더 작으면 swap
    {
        if(empty()) return;
        arr[1] = arr[--idx];
        int cur=1;
        int tmp;

        while(cur*2<idx)
        {
            tmp = cur;
            if(abs(arr[cur*2])<abs(arr[tmp]))
                tmp = cur*2;
            if(cur*2+1<idx && abs(arr[cur*2+1])<abs(arr[tmp]))
                tmp = cur*2+1;
            if(cur == tmp)
                break;
            swap(arr[cur],arr[tmp]);
            cur = tmp;
        }
    }

    int top()
    {
        if(idx==1)
            arr[1]=0;
        return arr[1];
    }
};

int main()
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    absHeap h;

    int N;
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