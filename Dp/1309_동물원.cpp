//
// Created by 이소정 on 2018. 5. 14..
//

#include <iostream>
using namespace std;

int main(){
    int N;
    int dp[100001][3];

    cin >> N;

    //한줄에 사자올 수 있는 경우
    dp[1][0] = 1; // 사자 0
    dp[1][1] = 1; // 사자 1 왼
    dp[1][2] = 1; // 사자 1 오

    for(int i=2;i<N+1;i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901; // i줄에 사자 0
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901; // i줄에 사자 1 오
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901; // i줄에 사자 1 왼
    }

    cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;

    return 0;
}
