#include <iostream>
#include <string>
using namespace std;

#define MAX 10000


//링크드 리스트 스택
class node{
public:
    int data;
    node* next;
};

class LinkStack {
private:
    node* head;
    int cnt = 0;
public:

    void push (int a){
            node* newTop = new node;
            if (head == NULL){
                newTop->data = a;
                newTop->next = NULL;
                head = newTop;
                cnt++;
            }
            else{
                newTop->data = a;
                newTop->next = head;
                head = newTop;
                cnt++;
            }
        }


    void pop(){
        if(head == NULL) return;
        else{
            node* old = head;
            head = head->next;
            cnt--;
            delete (old);
        }
    }

    int size(){
        return cnt;
    }

    bool empty(){
        return cnt==0;
    }

    int top(){
        return head->data;
    }
};


//배열 스택
class IntStack {
private:
    int a[10000];
    int t;

public:
    IntStack();
    int size();
    bool empty();
    int top();
    void push(int x);
    void pop();
};

IntStack::IntStack() : t(-1) {}

int IntStack::size() {
    return t+1;
}

bool IntStack::empty() {
    return (t<0);
}

int IntStack::top() {
    return a[t];
}

void IntStack::push(int x) {
    a[++t] = x;
}

void IntStack::pop() {
    --t;
}

int main() {
    LinkStack stack;
    int n;
    string s;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;

        if(s == "push"){
            int a;
            cin >> a;
            stack.push(a);
        }

        else if(s == "pop"){
            if(stack.empty())
                cout << "-1\n";
            else{
                cout << stack.top() << "\n";
                stack.pop();
            }
        }

        else if(s == "size"){
            cout << stack.size() << "\n";
        }

        else if(s == "empty"){
            if(stack.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }

        else if (s == "top") {
            if (stack.empty())
                cout << "-1\n";
            else {
                cout << stack.top() << "\n";
            }
        }
    }

    return 0;
}