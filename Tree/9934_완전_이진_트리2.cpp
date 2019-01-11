#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int arr[1025];

    int k;

    cin >> k;

    int cnt = 1;                //출력할 개수 ex) lv=0->1 lv=1->2 ...
    int sz = pow(2,k);          //2^k
    int d = sz;                 //공차 lv=0->x lv=1->8 lv=2->4 ...
    int idx = d/2;              //출력할 배열 idx

    for(int i=1;i<sz;i++)
    {
        cin >> arr[i];
    }

    for(int i=0;i<k;i++)                    //lv 만큼
    {
        for(int j=0;j<cnt;j++)              //cnt 만큼
        {
            cout << arr[idx] << " ";
            idx += d;
        }
        cnt *= 2;
        d /= 2;
        idx = d/2;
        cout << "\n";
    }

    return 0;
}