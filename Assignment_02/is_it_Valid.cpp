// Eliminate previous 0 by 1 or previous 1 by 0
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        stack<char> st;   // FIX: stack reset for every test case

        for (int i = 0; i < s.size(); i++)
        {
            if (!st.empty() && st.top() != s[i])
            {
                st.pop();     // delete opposite pair
            }
            else
            {
                st.push(s[i]);
            }
        }

        if (st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
