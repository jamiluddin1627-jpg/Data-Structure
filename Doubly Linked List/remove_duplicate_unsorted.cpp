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
    int count[100] = {0};
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

// Remove Duplicates from Unsorted Doubly Linked List (For loop version)
// void remove_unsorted_duplicates(Node *&head)
// {
//     Node *tmp = head;

//     for(Node *i = tmp; i != NULL && i->next != NULL; i = i->next)
//     {
//          for(Node *j = i; j->next != NULL; )
//            {
//             if(i->val == j->next->val)
//             {
//                 Node *deleteNode = j->next;
//                 j->next = j->next->next;

//                 if(deleteNode->next != NULL)
//                 deleteNode->next->prev = j;

//                 delete deleteNode;
//                 }
//             else
//             {
//                 j = j->next; // advance ONLY when no delete
//             }
//         }
//     }

// }

// Remove Duplicates from Unsorted Doubly Linked List (While loop version)
void remove_unsorted_duplicates(Node *&head)
{
    for(Node *i = head; i != NULL; i = i->next)
    {
        Node *j = i;
        while(j->next != NULL)
        {
            if(i->val == j->next->val)
            {
                Node *deleteNode = j->next;
                j->next = j->next->next;// move before delete

                if(deleteNode->next != NULL)
                {
                    deleteNode->next->prev = j;
                }

                delete deleteNode;
            }
            else
            {
                j = j->next; // only move when no delete
            }
        }
    }
}

void remove_unsorted_duplicates2(Node *&head)
{
    Node *tmp = head;
    while( tmp != NULL && tmp->next != NULL)
    {
        Node *tmp2 = tmp->next;
        while(tmp2 != NULL)
        {
            if(tmp->val == tmp2->val)
            {
                Node *deleteNode = tmp2;
                tmp2 = tmp2->next; // move before delete
                if(deleteNode->prev != NULL)
                {
                    deleteNode->prev->next = deleteNode->next;
                }
                else
                {
                    head = deleteNode->next; // if deleteNode is head, move head to next
                }
                if(deleteNode->next != NULL)
                {
                    deleteNode->next->prev = deleteNode->prev; // if deleteNode is tail, deleteNode->next will be NULL, so no need to update tail
                }
                delete deleteNode;
            }
            else
            {
                tmp2 = tmp2->next; // only move when no delete
            }
        }
        tmp = tmp->next;
    }
}

// Delete Node
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
    
    cout<<"---------Delete From Position-----------"<<endl;
   
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
        cout<<"Node Deleted From Position: "<<pos<<endl;
        return;
        }
        for (int i = 1 ; i <= pos-1; i++)
        {
            if(tmp->next == NULL)
            {
                cout<<"Position Out of Bound"<<endl;
                return;
            }
            tmp = tmp->next;
        }
        Node *deleteNode = tmp->next;
        tmp->next = tmp->next->next;
        if(deleteNode->next != NULL)
        {
            deleteNode->next->prev = tmp;
        }
        else
        {
            tail = tmp;
        }
        delete deleteNode;
        cout<<"Node Deleted From Position: "<<pos<<endl;
}

void print(Node *head)
{
    Node *tmp = head;
    while(tmp != NULL)
    {
        cout<< tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
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
    print(head);
    remove_unsorted_duplicates(head);
    print(head);
    int pos;
    cout<<"Enter Position to Delete: "<<endl;
    cin>>pos;
    delete_Node(head, tail, pos);
    print(head);
    return 0;
}