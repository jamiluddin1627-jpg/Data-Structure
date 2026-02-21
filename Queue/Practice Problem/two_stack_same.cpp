#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myStack
{
    public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
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
        return tail->data;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return sz == 0;
    }
};

int main()
{
    myStack s1;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s1.push(x);
    }
    myStack s2;
    int n2;
    cin >> n2;
    for(int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        s2.push(x);
    }
    
    if(s1.size() != s2.size())
    {
        cout << "Not Same";
        return 0; // If sizes are different, then they are not same and the program will be terminated immediately.
    }
    while(!s1.empty())
    {
        if(s1.top() != s2.top())
        {
            cout << "Not Same";
            return 0; // If any element is different, then they are not same and the loop will be terminated immediately.
        }
        s1.pop();
        s2.pop();
    }
    cout << "Same";
    return 0;
}