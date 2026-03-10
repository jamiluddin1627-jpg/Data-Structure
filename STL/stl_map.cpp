#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int>mp;
    
    //using insert function
    mp.insert({"Alice", 85});
    mp.insert({"Bob", 90});
    //using array index operator
    mp["Charlie"] = 78;
    mp["David"] = 92;
    mp["Jamil"] = 88;
    mp["Jamil"] = 95; //update Jamil's marks

    //accessing values
    cout << "Alice's marks: " << mp["Alice"] << endl;
    cout << "Bob's marks: " << mp["Bob"] << endl;
    cout << "Charlie's marks: " << mp["Charlie"] << endl;
    cout << "David's marks: " << mp["David"] << endl;
    cout << "Jamil's marks: " << mp["Jamil"] << endl;

    //iterating through the map
    for(auto it: mp)
    {
        cout << it.first << ": " << it.second << endl;
    }

    if(mp.count("Jamil") > 0)
    {
        cout << "Jamil is present in the map."<<"Jamil's marks: "<<mp["Jamil"] << endl;
    }
    else
    {
        cout << "Jamil is not present in the map." << endl;
    }

    return 0;
    
}