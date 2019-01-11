#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    int a,b;
    int minPack = 1000;
    int minPiece = 1000;
    int price = 0;

    cin >> n >> m;

    //패키지와 낱개 가격 갱신해놓기
    for(int i=0;i<m;i++){
        cin >> a >> b;
        minPack = min(a,minPack);
        minPiece = min(b,minPiece);
    }

    //낱개6개가 패키지보다 쌀 경우
    if(minPack > minPiece*6)
        minPack = minPiece*6;

    //1-5개가 패키지로 사는게 싼 경우
    if(n%6*minPiece > minPack)
        price += (n/6 + 1) * minPack;
    else
        price += (n/6 * minPack) + (n%6 * minPiece);

    cout << price;
    return 0;
}