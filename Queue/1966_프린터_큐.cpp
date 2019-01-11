#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int t;

    cin >> t;

    while(t--)
    {
        queue<int> q;
        int N,idx;
        int cnt = 0;
        int print = 0;
        int imp[100] = {0};

        cin >> N >> idx;

        for(int i=0;i<N;i++)
        {
            cin >> imp[i];
            q.push(imp[i]);
        }

        sort(imp,imp+N);
        reverse(imp,imp+N);

        while(1)
        {
            if(q.front()!=imp[cnt])        //큐의 맨앞이 max중요도 아니면
            {
                q.push(q.front());              //뒤로 옮기고
                q.pop();
                idx--;                          //idx 앞으로 당기기 + 맨앞에서 당길 때 예외처리
                if(idx==-1)
                    idx = q.size()-1;
            }
            else                                //큐의 맨앞이 max중요도 일때
            {
                if(idx==0)                      //인쇄될 종이가 앞일때
                {
                    print++;                    //인쇄하고 종료
                    break;
                }
                q.pop();                        //인쇄, idx당기기, max중요도 변경
                idx--;
                print++;
                cnt++;
            }
        }

        cout << print << "\n";

    }

    return 0;
}