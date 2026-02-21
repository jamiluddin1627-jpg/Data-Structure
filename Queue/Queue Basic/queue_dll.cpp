#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node *prev;
    Node(int v)
    {
        this->val = v;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myQueue{
    public:
    int sz = 0;
    Node *head = NULL;
    Node *tail = NULL;
    
    void push(int v)
    {
        sz++;
        Node *newNode = new Node(v);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        tail = newNode;
    }
    void pop()
    {
        if(head == NULL) return;
        sz--;
        Node *deleteNode = head;
        head = head->next;
        if(head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        delete deleteNode;
    }
    int front()
    {
        if (head == NULL) return -1;
        return head->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        if(sz==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    myQueue q;
    int n;
    cin>>n;
    for(int i = 0; i<n ; i++)
    {
        int v;
        cin>>v;
        q.push(v);
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    
    myQueue p;
    int pn;
    cin>>pn;
    for(int i = 0; i<pn ; i++)
    {
        int v;
        cin>>v;
        p.push(v);
    }
    while(!p.empty())
    {
        cout<<p.front()<<" ";
        p.pop();
    }
    cout<<endl;
    return 0;
}