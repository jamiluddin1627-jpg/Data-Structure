 #include<bits/stdc++.h>
 using namespace std;
 
 int main()
 {
     stack<int> st;
     queue<int> q;
     int n;
     cin>>n;
     for(int i = 0; i<n; i++)
     {
         int v;
         cin>>v;
         st.push(v);
     }
     int n2;
     cin>>n2;
     for(int i = 0; i<n2; i++)
     {
         int v;
         cin>>v;
         q.push(v);
     }
     if(st.size() != q.size())
     {
         cout<<"NO"<<endl;
         return 0;
     }
     while(st.size()) // or while(!st.empty()) // st.size() will also work because if size is 0 then it will be false and loop will be terminated.
     {
         if(st.top()!=q.front())
         {
             cout<<"NO"<<endl; 
             return 0;
         }
         st.pop();
         q.pop();
     }
     cout<<"YES"<<endl;
     return 0;
 }