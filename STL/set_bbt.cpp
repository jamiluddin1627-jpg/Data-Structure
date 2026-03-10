#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        s.insert(x); //O(log n)
    }
    
   // reverse(s.begin(), s.end()); //O(n) - not possible in set as it is ordered
    for(auto it: s)
    {
        cout << it << " "; //O(n)
    }

    return 0;
}