#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101010

vector<int> T[MAX];
bool visit[MAX] = {false};
int par[MAX] = {0};

void findPar(int root)
{
    queue<int> q;
    q.push(root);
    visit[root] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(auto i:T[cur])
        {
            if(!visit[i])
            {
                q.push(i);
                par[i] = cur;
                visit[i] = true;
            }
        }
    }

}

int main()
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    int u,v;

    cin >> N;
    N--;

    for(int i=0;i<N;i++)
    {
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    findPar(1);


    for(int i=2;i<=N+1;i++)
    {
        cout << par[i] << "\n";
    }

    return 0;
}