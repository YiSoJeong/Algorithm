//
// Created by 이소정 on 2018. 5. 6..
//
#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    int product = 0;
    int arr[10]={0};

    cin >> a >> b >> c;

    product = a*b*c;

    //마지막 자리수 index 증가
    //자리수 버림
    while(product/10 != 0){
        arr[product%10]++;
        product /= 10;
    }
    //1자리수 index 증가
    arr[product%10]++;

    for(int i = 0;i < 10;i++){
        printf("%d\n",arr[i]);
    }


    return 0;
}