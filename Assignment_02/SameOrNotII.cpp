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
class myStack{
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
        Node *deleteNode = tail;
        tail = tail->prev;
        if(tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        delete deleteNode;
    }
    int top()
    {
        if (head == NULL) return -1;
        return tail->val;
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
    myStack st;
    myQueue q;
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<n; i++)
    {
        int v;
        cin>>v;
        st.push(v);
    }

    for(int i = 0; i<m; i++)
    {
        int v;
        cin>>v;
        q.push(v);
    }
    if(st.size() != q.size())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    while(!st.empty())
    {
        if(st.top() != q.front())
        {
            cout<<"NO"<<endl;
            return 0;
        }
        st.pop();
        q.pop();
    }
    cout<<"YES"<<endl;
    return 0;
}