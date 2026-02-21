#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int val;
    Node *next;
    Node *prev;
    Node (int v)
    {
        this->val = v;
        this-> next = NULL;
        this-> prev = NULL;
    }
};

void insert(Node *&head, Node *&tail, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
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

void delete_Node(Node *&head, Node *&tail, int pos)
{
    Node *tmp = head;
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    
    if(pos < 0)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    
    cout<<"Delete From Position: "<<endl;
   
    if (pos == 0)
    {
        Node *targetHead = head;
        head = head->next;

        if(head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL;
        }
        
        delete targetHead;
        cout<<"Head Node Deleted"<<endl;
        return;
    }
    for (int i = 1 ; i <= pos-1; i++)
    { 
        tmp = tmp->next;
    }
    if(tmp->next == NULL)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    Node *targetNode = tmp->next;
    //tmp->next->next->prev = tmp;//same, if i write this before tmp->next = tmp->next->next; then it will shows error.
    tmp->next = tmp->next->next;
    //tmp->next->next->prev = tmp;
    if(targetNode->next != NULL)
    {
    targetNode->next->prev = tmp;
    }
    else
    {
        tail = tmp;
    }
    delete targetNode;
    cout<<"Node Deleted From Position: "<<pos<<endl;
}

void print(Node *head)
{
    Node *tmp = head;
    while(tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
}
int main ()
{
    Node *head = NULL;
    Node *tail = NULL;
    
    while(true)
    {
        int v;
        cin>> v;
        if (v == -1) break;
        insert(head, tail, v);
    }
    print(head);
    cout<<endl;
    int p;
    cout<<"Enter position to delete: "<<endl;
    cin>>p;
    delete_Node(head, tail, p);
    print(head);
    return 0;
}
