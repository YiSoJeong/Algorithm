#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int x_1;
    int y_base, y_max, y_add;
    int use;

    cin >> x_1 >> y_base >> y_max >> y_add >> use;

    x_1 = x_1*use;

    //사용량 초과 시
    if(use > y_max)
    {
        y_base = y_base + (use-y_max)*y_add;
    }

    cout << min(x_1,y_base);

    return 0;
}