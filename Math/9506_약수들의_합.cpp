#include <iostream>
using namespace std;

int main(){
    int n;

    cin >> n;

    while(1){
        int divisor[100001] = {0};
        int sum = 1;

        if(n==-1) break;

        for(int i=2;i<=n-1;i++){
            if(n%i==0){
                divisor[i]++;
                sum += i;
            }
        }

        if(sum==n){
            cout << n << " = 1";
            for(int i=2;i<=n-1;i++){
                if(divisor[i]==1){
                    cout << " + " << i;
                }
            }
            cout << "\n";
        }
        else{
            cout << n << " is NOT perfect.\n";
        }

        cin >> n;
    }

    return 0;
}