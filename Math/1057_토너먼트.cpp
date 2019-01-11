/*
 * 두 선수가 대결하는 라운드 찾기
 * 절반씩 줄여나가면서 구한다.
 */
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int& a,int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int n,a,b;
    int round = 1;

    cin >> n >> a >> b;

    if(a>b)
        swap(a,b);

    while(1)
    {
        //a(홀수)|a+1 일때까지
        if(a % 2 == 1 && a == b - 1)
            break;

        //나머지를 안더하면 0일 때 무한루프
        a  = a/2 + a%2;
        b  = b/2 + b%2;

        round++;
    }

    cout << round;

    return 0;
}