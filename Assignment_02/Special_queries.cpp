#include <bits/stdc++.h>

using namespace std;



int main()
{
    queue<string> q;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n == 1)
        {
            if(q.empty())
            {
                cout<<"Invalid"<<endl;
            }
            else{
            cout<<q.front()<<endl;
            q.pop();
            }
        }
        else
        {
            string nm;
            cin>> nm;
            q.push(nm);
        }
        
    }

    return 0;
}
