#include<bits/stdc++.h>
using namespace std;

class myQueue{
    public:
    list<int> l;
    void push(int v)
    {
         l.push_back(v);
    }
    void pop()
    {
        if(l.empty()) return;
        l.pop_front();
    }
    int front()
    {
        if (l.empty()) return -1;
        return l.front();
    }
    int size()
    {
        return l.size();
    }
    bool empty()
    {
         return l.empty();
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
    
    return 0;
}