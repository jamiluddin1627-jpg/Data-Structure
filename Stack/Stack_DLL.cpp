#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int v){
        this->val = v;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myStack{
    
    public:
    int sz = 0;  
    Node* head = NULL;
    Node* tail = NULL;

    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
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
        return tail->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        if(sz == 0) return true;
        else return false;
    }

};


int main(){
    myStack st;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}