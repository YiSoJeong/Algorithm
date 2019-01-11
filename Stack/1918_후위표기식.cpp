#include <iostream>
#include <string>
using namespace std;

#define MAX 100


//array stack
template <typename T>
class ArrayStack
{
private:
    T arr[MAX] = {0};
    int idx = 0;
public:
    void push(T data)
    {
        if(idx==MAX)
            return;
        arr[idx++] = data;
    }

    void pop()
    {
        if(idx==0)
            return;
        idx--;
    }

    T size()
    {
        return idx;
    }

    bool empty()
    {
        return idx==0;
    }

    T top()
    {
        if(idx==0)
            return -1;
        return arr[idx-1];
    }
};



//linkedlist array
class node{
public:

};



int main()
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    ArrayStack<char> st;
    string s;

    cin >> s;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
            st.push(s[i]);

        else if(s[i]==')')
        {
            while(!st.empty())
            {
                if(st.top()=='(')
                {
                    st.pop();
                }
                else
                {
                    cout << st.top();
                    st.pop();
                }
            }
        }

        else if(s[i]=='-'||s[i]=='+')
        {
            st.push(s[i]);
        }

        else if(s[i]=='*'||s[i]=='/')
        {
            for(int j=i;j>0;j--)
            {
                if(s[j]=='-'||s[j]=='+')
                {
                    cout<<s[j];
                    st.pop();
                    st.push(s[i]);
                }
            }
        }

        else if('A'<=s[i]&&s[i]<='Z')
        {
            cout << s[i];
        }
    }

    for(int i=st.size();i>0;i--)
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}