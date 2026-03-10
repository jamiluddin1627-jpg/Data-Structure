#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>>pq;

    while(true)
    {
        int c;
        cin>>c;

        if(c==0)
        {
            int x;
            cin>>x;
            pq.push(x);
        }
        else if(c==1)
        {
            if(pq.empty())
            {
                cout<<"Empty\n";
            }
            else
            {
                pq.pop();
                cout<<"Top popped\n";
            }
        }
        else if(c == 2)
        {
            if(pq.empty())
            {
                cout<<"Empty\n";
            }
            else
            {
                cout<<"Top value is: "<<pq.top()<<"\n";
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}