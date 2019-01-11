#include <iostream>
#include <string>
using namespace std;

#define MAX 20

class Queue {
private:
    int r, f;
    int* queue;
    int index;
    int _size;
public:
    Queue(int s) {
        queue = new int[s];
        index = s;
        _size = 0;
        r = 0;
        f = 0;
        for (int i = 0; i < s; i++) queue[i] = 0;
    }
    bool is_empty() {
        if (r == f) return 1;
        else return 0;
    }
    bool is_full() {
        if ((r + 1) % index == f) return 1;
        else return 0;
    }
    void push(int data) {
        if (is_full()) return;
        else {
            r = (r + 1) % index;
            queue[r] = data;
            _size++;
        }
    }
    int pop() {
        if (is_empty()) return -1;
        else {
            f = (f + 1) % index;
            _size--;
            return queue[f];
        }
    }
    int size() {
        return _size;
    }
    int front() {
        if (is_empty()) return -1;
        else return queue[(f + 1) % index];
    }
};

class CircularQueue
{
private:
    int arr[MAX] = {0};
    int f = 0;
    int r = 0;
public:
    bool empty()
    {
        return r==f;
    }

    int size()
    {
        return r-f+1;
    }

    void enqueue(int a)
    {
        if (size()==MAX)
            return;
        else
        {
            r = (r+1) % MAX;
            arr[r] = a;
        }
    }

    void dequeue()
    {
        if (empty())
            return;
        else
        {
            f = (f+1) % MAX;
        }

    }

    int front()
    {
        return arr[f];
    }

    int back()
    {
        return arr[r];
    }
};


class node
{
public:
    int data;
    node* next = NULL;
};

class LinkQueue
{
private:
    int cnt = 0;
    node* head = NULL;
    node* tail = NULL;
public:
    bool empty()
    {
        return cnt==0;
    }

    int size()
    {
        return cnt;
    }

    int front()
    {
        if(head == NULL)
            return -1;
        else
            return head->data;
    }

    int back()
    {
        if(tail == NULL)
            return -1;
        else
            return tail->data;
    }

    void enqueue(int a)
    {
        node* tmp = new node;
        tmp->data = a;
        tmp->next = NULL;
        if(empty())
        {
            head = tail = tmp;
            cnt++;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
            cnt++;
        }
    }

    void dequeue()
    {
        node* old = head;
        if(head == NULL)
        {
            return;
        }
        if(head == tail)
        {
            head = tail = NULL;
            cnt--;
        }
        else
        {
            head = head->next;
            cnt--;
        }
        delete old;
    }
};


class IntQueue {
private:
    int a[10000];
    int f=0;
    int r=-1;

public:
    IntQueue() : f(0), r(-1) {}
    int size()
    {
        return r-f+1;
    }
    bool empty()
    {
        return f>r;
    }
    int front()
    {
        return a[f];
    }
    int back()
    {
        return a[r];
    }
    void enqueue(int x)
    {
        a[++r] = x;
    }
    void dequeue()
    {
        f++;
    }
};

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    //CircularQueue q;
    LinkQueue q;
    //IntQueue st;
    int n;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;

        if(s == "push"){
            int a;
            cin >> a;
            q.enqueue(a);
        }

        else if(s == "pop"){
            if(q.empty())
                cout << "-1\n";
            else{
                cout << q.front() << "\n";
                q.dequeue();
            }
        }

        else if(s == "size"){
            cout << q.size() << "\n";
        }

        else if(s == "empty"){
            if(q.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }

        else if (s == "front") {
            if (q.empty())
                cout << "-1\n";
            else {
                cout << q.front() << "\n";
            }
        }

        else if (s == "back") {
            if (q.empty())
                cout << "-1\n";
            else {
                cout << q.back() << "\n";
            }
        }
    }

    return 0;
}