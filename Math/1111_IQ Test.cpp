#include <iostream>
using namespace std;

int main(){
    int n;
    int arr[50] = {0};

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    //다음 수는 무엇이든 올 수 있다.
    if(n==1)
        cout << 'A';

    else if(n==2){
        //두 수가 같으면 a,b에 관계없이 다음 수가 정해진다.
        if (arr[1] == arr[0])
            cout << arr[0];
        //두 수가 다르면 여러 값이 가능하다.
        else
            cout << 'A';
    }

    else if(n>=3) {
        int a = 0, b = 0;
        //a와 b구하기

        //분모가 0이 되지 않도록 예외처리
        if(arr[1] != arr[0]) {
            a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
        }
        b = arr[1] - arr[0] * a;

        for (int i = 2; i < n; i++) {
                //분모가 0이 되지 않도록 예외처리
            if (arr[i-1] != arr[i-2] && (a != (arr[i] - arr[i-1]) / (arr[i-1] - arr[i-2]))
                || b != arr[i] - arr[i-1] * a) {
                cout << 'B';
                return 0;
            }
        }
        cout << arr[n-1]*a + b;
    }
    return 0;
}