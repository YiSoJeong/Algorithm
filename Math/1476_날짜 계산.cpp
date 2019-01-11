#include <iostream>
using namespace std;

int main(){
    int E,S,M;
    int year = 0;

    cin >> E >> S >> M;

    while(1){
        //나머지가 0인 경우를 위해 1을 먼저 더해주고 판단
        if((year%15 + 1) == E && (year%28 + 1) == S && (year%19 + 1) == M){
            break;
        }
        year++;
    }

    cout << year+1;

    return 0;
}