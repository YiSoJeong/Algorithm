#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next = NULL;
};

class circularLinkedList
{
private:
    node* head = NULL;
    node* tail = NULL;
    node* cur = NULL;
    int cnt = 0;
public:
    bool empty()
    {
        return cnt == 0;
    }

    int size()
    {
        return cnt;
    }

    void addNode(int n)
    {
        node* tmp = new node;
        tmp->data = n;
        if(empty())
        {
            head = tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
            tail->next = head;
        }
        cnt++;
    }
    void removeFront()
    {
        if(empty())
            return;
        else
        {
            node *old = head;
            head = head->next;
            delete (old);
            cnt--;
        }
    }
    int removePosition(int n)
    {
        node *pre=new node;
        node *tmp=new node;

        if(cur == NULL)
           tmp=head;
        else tmp = cur;

        for(int i=1;i<n;i++)
        {
            pre=tmp;
            tmp=tmp->next;
        }

        node* old = tmp;
        int ret = tmp->data;
        pre->next = tmp->next;
        cur = tmp -> next;
        delete(old);
        cnt--;
        return ret;
    }

};

int main()
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    circularLinkedList c;
    int idx = 0;
    int M,N;

    cin >> N >> M;

    for(int i=1;i<=N;i++)
    {
        c.addNode(i);
    }

    cout << "<";
    while(!c.empty())
    {
        if(c.size()==1)
        {
            cout << c.removePosition(M);
        }
        else
            cout << c.removePosition(M) << ", ";
    }
    cout << ">";

    return 0;
}