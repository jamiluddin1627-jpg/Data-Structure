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

void insert (Node *&head, Node *&tail, int v)
{
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

void duplicate_check(Node *head)
{
    int count[] = {0};
    Node *tmp = head;
    bool duplicate = false;
    while(tmp != NULL)
    {
       if(count[tmp->val]++ > 0)
       {
        duplicate = true;
        break;
       }
        tmp = tmp->next;
    }
    if(duplicate)
    {
        cout<<"Duplicate Found"<<endl;
    }
    else
    {
        cout<<"No Duplicate Found"<<endl;
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
    duplicate_check(head);
    return 0;
}