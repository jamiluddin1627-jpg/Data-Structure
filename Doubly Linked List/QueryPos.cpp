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

void insert(Node *&head, Node *&tail, int v){

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

void sort(Node *&head)
{
    Node *i = head;
    
    while(i != NULL && i->next != NULL)
    {
        Node *j = i->next;
        while(j != NULL)
        {
            if(i->val > j->val)
            {
                swap(i->val, j->val);
            }
            j = j->next;
        }
        i = i->next;
    }
}

void sort2(Node *&head)
{
    Node *tmp = head;
    while(tmp != NULL && tmp->next != NULL)
    {
         if(tmp->val > tmp->next->val)
         {
             swap(tmp->val, tmp->next->val);
             tmp = head;
         }
         else
         {
             tmp = tmp->next;
         }
    }
}

void sort3(Node *&head)
{
    for(Node *i = head; i != NULL && i->next != NULL; i = i->next)
    {
         for(Node *j = i; j->next != NULL; j = j->next)
         {
             if(i->val > j->next->val)
             {
                 swap(i->val, j->next->val);
             }
         }
    }
}
void print(Node *&head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int v;
        cin>> v;
        if(v == -1) break;
        insert(head, tail, v);
    }
    print(head);
    cout<<"----------Sort1--------"<<endl;
    sort(head);
    print(head);
    cout<<"----------Sort2--------"<<endl;
    sort2(head);
    print(head);
    cout<<"----------Sort3--------"<<endl;
    sort3(head);
    print(head);
    return 0;
}