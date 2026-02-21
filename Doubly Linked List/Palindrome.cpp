#include <bits/stdc++.h>
using namespace std;

class Node
{

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

void palindrome(Node *head, Node *tail)
{
    Node *i = head;
    Node *j = tail;
    bool flag = true;

    while (i != j && i->next != j)
    {
        if (i->val != j->val)
        {
            flag = false;
            break;
        }
        i = i->next;
        j = j->prev;
    }

    if (flag)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
}

void print(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int v;
        cin >> v;
        if (v == -1)
            break;
        insert(head, tail, v);
    }
    print(head);
    cout << endl;
    palindrome(head, tail);
    print(head);
    return 0;
}