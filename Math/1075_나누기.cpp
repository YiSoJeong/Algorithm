/*
 * 계산 과정을 코드로 작성
 * 컴퓨터가 계산해주기 때문에 과정만 작성하면 됨
 */

#include <iostream>
using namespace std;

int main(){
    int n,f;

    cin >> n >> f;

    //마지막 두자리수 버림
    n = (n/100) * 100;

    //n에 1~99까지 더하면서 f와 나누어 떨어지는 수 구하기
    for(int i=0;i<100;i++){
        if((n + i) % f == 0){
            n = n + i;
            break;
        }
    }

    //구한 n을 마지막 두자리수만 출력
    printf("%02d", n % 100);
    return 0;
}