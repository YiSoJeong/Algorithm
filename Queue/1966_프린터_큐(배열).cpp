#include <iostream>
using namespace std;

class IntQueue{
private:
    int a[5000] = {0};
    int f=0;
    int r=-1;
public:
    void push(int x)
    {
        a[++r] = x;
    }
    void pop()
    {
        f++;
    }
    bool empty()
    {
        return f>r;
    }
    int size()
    {
        return r-f+1;
    }
    int front()
    {
        return a[f];
    }
    int back()
    {
        return a[r];
    }
    int max()
    {
        int m = 0;
        for(int i=f;i<=r;i++)
        {
            if(a[i]>m)
                m = a[i];
        }
        return m;
    }
};



int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int T;

    cin >> T;
    while(T--)
    {
        IntQueue st;
        int idx;
        int print = 0;
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++)
        {
            int p;
            cin >> p;
            st.push(p);
            if(i==m)
            {
                idx = p;
            }
        }

        while(1)
        {
            int M = st.max();
            if(st.front()<M)
            {
                st.push(st.front());
                st.pop();
            }

            else if(st.front()==M)
            {
                print++;
                st.pop();
                if (st.front()==idx)
                {
                    cout << print << "\n";
                    break;
                }
            }
        }



    }

    return 0;
}