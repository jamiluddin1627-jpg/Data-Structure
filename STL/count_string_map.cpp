#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    string word;
    stringstream ss(str);
    map<string, int> mp;
    while(ss >> word)
    {
        mp[word]++;
    }
    for(auto it: mp)
    {
        cout << it.first << ": " << it.second << endl;
    }
    return 0;
}