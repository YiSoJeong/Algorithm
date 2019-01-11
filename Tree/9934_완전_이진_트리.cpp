#include <iostream>
#include <vector>
using namespace std;

vector <int> v[10];
int a[1024];
int n;

int power(int n)
{
    if(n==0)
        return 1;
    return 2*power(n-1);
}

void midNum(int idx,int op,int l)
{
    if(l==n)
        return;
    else
    {
        v[l].push_back(a[idx - 1]);
        l++;
        midNum(idx - op,op/2,l);
        midNum(idx + op,op/2,l);
    }
}

int main()
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> n;

    int size = power(n);

    for(int i=0;i<size-1;i++)
    {
        cin >> a[i];
    }

    midNum(size/2,size/4,0);

    for(int i=0; i<n; i++)
    {
        for(auto j:v[i])
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}