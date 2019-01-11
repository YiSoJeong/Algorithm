#include <iostream>
#include <string>
using namespace std;

#define MAX 50

class StringStack{
private:
    char s[50];
    int t = 0;
public:
    int size() {
        return t;
    }
    bool empty() {
        if (t == 0) return true;
        else return false;
    }
    char top() {
        if (t == 0) return 'e';
        return s[t-1];
    }
    void push(char a) {
        if(t==MAX) return;
        s[t++] = a;
    }
    void pop() {
        if (t == 0) return;
        t--;
    }
};


int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    string s;

    cin >> n;
    while(n--){
        bool flag = true;
        StringStack st;
        cin >> s;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(') {
                st.push('(');
            }
            else if(s[i] == ')') {
                if (st.empty())
                    flag = false;
                else
                    st.pop();
            }
        }
        if(flag && st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}