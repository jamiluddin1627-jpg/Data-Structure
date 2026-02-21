#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int v){
        this->val = v;
        this->next = NULL;
    }
};

class myQueue{
    
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
        tail = newNode;
    }

    void pop()
    {
        if (head == NULL) return; // Queue is empty, nothing to pop
        sz--;
        Node *deleteNode = head;
        head = head->next;
        if(head == NULL)
        {
            tail = NULL;
        }
        delete deleteNode;
    }

    int front()
    {
        if(head == NULL) return -1; // Return -1 if queue is empty
        return head->val;
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
    myQueue q;    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}