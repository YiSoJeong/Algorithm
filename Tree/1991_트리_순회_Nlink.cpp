#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class NlinkTree;

template <typename T>
class Node {
public:
    T data;
    Node* par;
    vector<Node*> chi;

    Node()
    {
        this->data = NULL;
        this->par = NULL;
    }

    Node(T data)
    {
        this->data = data;
        this->par = NULL;
    }

    ~Node(){}

    void setParent(Node* par)
    {
        this->par = par;
        return;
    }

    void insertChild(Node* chi)                         //chi노드를 chi벡터에 추가
    {
        this->chi.push_back(chi);
        return;
    }

    void delChild(Node* chi)                            //chi노드를 chi벡터에서 삭제
    {
        for(int i=0;i<this->chi.size();i++)
        {
            if(this->chi[i]==chi)
            {
                this->chi.erase(this->chi.begin()+i);
            }
        }
        return;
    }
};

template <typename T>
class NlinkTree
{
private:
    Node<T>* root;
    vector<Node<T>*> node_list;
    int size = 0;
public:
    NlinkTree()
    {
        root = NULL;
    }

    NlinkTree(T data)
    {
        root = new Node<T>(data);
        node_list.push_back(root);
    }

    ~NlinkTree(){}

    Node<T>* getRoot()
    {
        return root;
    }

    void insertNode(T parent_data, T data)                  //parent_data에 data를 자식으로 추가
    {
        Node<T>* par;
        for(auto &i : this->node_list)
        {
            if(i->data == parent_data)
            {
                par = i;
                Node<T>* newnode = new Node<T>(data);       //data를 가지는 노드를 만들고
                par->insertChild(newnode);                  //par노드의 chi로 만든 노드 추가
                newnode->setParent(par);                    //만든 노드의 부모를 par로
                node_list.push_back(newnode);               //노드 리스트에 추가
                return;
            }
        }
        size++;
        return;
    }

    void delNode(T data)                                    //data노드 삭제
    {
        Node<T>* nownode;
        Node<T>* par;
        for(auto &i:this->node_list)
        {
            if(i->data == data)
            {
                nownode = i;
                par = nownode->par;
                for(auto &c:nownode->chi)
                {
                    par->insertChild(c);      //n개의 자식들을 부모의 자식으로
                    c->setParent(par);        //자식들의 부모를 헌재 노드의 부모로
                }
                par->delChild(nownode);
                this->node_list.erase(this->node_list.begin()+i);
                delete nownode;
            }
        }
        size--;
        return;
    }

    void printChild(T data)
    {
        for(auto &i:this->node_list)
        {
            if(i->data == data)
            {
                if(i->chi.size()==0)
                    cout << "0";
                for(auto c:i->chi)
                {
                    cout << c->data << " ";
                }
                cout << "\n";
                return;
            }
        }
        return;
    }

    int depth(T data)
    {
        int d = 0;
        for(auto &i:this->node_list)
        {
            if(i->data == data)
            {
                while(i->par != NULL)
                {
                    d++;
                    i = i->par;
                }
            }
        }
        return d;
    }

    void preorder(Node<T>* n)
    {
        cout << n->data << " ";

        for(auto &i:n->chi)
        {
            preorder(i);
        }
    }


    void postorder(Node<T>* n)
    {
        for(auto &i:n->chi)
        {
            postorder(i);
        }
        cout << n->data << " ";
    }
};


int main()
{
    NlinkTree<int> tree(1);
    int N;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        int data,chi;
        cin >> data;
        cin >> chi;
        while(chi!=0)
        {
            tree.insertNode(data, chi);
            cin >> chi;
        }
    }

    tree.preorder(tree.getRoot());
    cout << "\n";

    tree.postorder(tree.getRoot());
    cout << "\n";
    return 0;
}