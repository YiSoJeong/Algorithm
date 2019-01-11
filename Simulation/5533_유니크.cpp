#include <iostream>
using namespace std;

int main(){
    int n;
    int score[201][4];
    bool same;

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++)
            cin >> score[i][j];
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            same = true;
            for(int k=0;k<n;k++){
                if(j != k && score[j][i] == score[k][i])
                    same = false;
            }
            if (same)
                score[j][3] += score[j][i];
        }
    }

    for(int i=0;i<n;i++){
        cout << score[i][3] << "\n";
    }
}