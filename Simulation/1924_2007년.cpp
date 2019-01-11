/*
 * 나눗셈을 통한 요일 계산
 */

#include <iostream>
#include <string>
using namespace std;

int main(){
    string week[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int x,y,idx;
    int day = 0;

    cin >> x >> y;

    //x달 전까지 모든 날 더하기 (1월 제외)
    for(int i = 1; i<x;i++){
        day += month[i-1];
    }

    //y일 더하기
    day += y;

    //7로 나눈 나머지 idx에 저장
    idx = day % 7;

    cout << week[idx];

    return 0;
}