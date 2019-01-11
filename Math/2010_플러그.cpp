/*
 * 멀티탭의 플러그끼리도 연결가능 고려
 */

#include <iostream>
using namespace std;

int main(){
    int n; //멀티탭 개수
    int plug[500000] = {0};
    int cnt = 0;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> plug[i];
    }

    for(int i=0;i<n;i++){
        cnt += (plug[i] - 1);
    }

    cnt++;
    cout << cnt;
    return 0;
}