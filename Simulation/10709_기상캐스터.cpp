#include <iostream>
using namespace std;

int main(){
    char a[101][101];
    int b[101][101] = {0};
    bool iscloud = false;
    int time = 0;
    int h,w;

    cin >> h >> w;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if (a[i][j] == 'c' && time==0)
            {
                b[i][j] = 0;
                iscloud = true;
            }
            else if (a[i][j] == 'c' && time!=0)
            {
                b[i][j] = 0;
                time=0; //시작시간 초기화
                iscloud = true;
            }
            else
            {
                //구름이 있었으면 경과시간
                if(iscloud)
                {
                    b[i][j] = time;
                }
                //없었으면 -1
                else
                {
                    b[i][j] = -1;
                }
            }
            time++;
        }
        iscloud = false;
    }

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}