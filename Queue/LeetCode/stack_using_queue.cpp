#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
        // Constructor
    }
    
    // Push operation: O(1)
    void push(int x) {
        q.push(x);
    }
    // Pop operation: O(N)
    int pop() {
        queue<int> newQ;
        int last;
        
        // সব এলিমেন্ট নতুন কিউতে পার করছি, শেষেরটা বাদে
        while(!q.empty())
        {
            int k = q.front();
            q.pop();
            
            if(q.empty())
            {
                last = k; // এটাই শেষের এলিমেন্ট (যেটা ডিলিট হবে)
                break;    // এটাকে newQ তে আর পুশ করব না
            }
            newQ.push(k);
        }
        q = newQ; // মেইন কিউ আপডেট করলাম
        return last;
    }
    
    // Top operation: O(N)
    int top() {
        queue<int> newQ;
        int last;
        
        while(!q.empty())
        {
            int k = q.front();
            q.pop();
            
            if(q.empty())
            {
                last = k; // এটাই শেষের এলিমেন্ট (Stack Top)
            }
            newQ.push(k); // টপ দেখার সময় এলিমেন্ট হারানো যাবে না, তাই সব পুশ করছি
        }
        q = newQ; // মেইন কিউ আপডেট করলাম
        return last;
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;
    
    int n;
    cout << "How many elements?"<<endl;
    cin >> n;
    
    cout << "Enter the elements to push onto the stack: "<<endl;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        st.push(val);
    }
    
    cout << "\n-----------------------" << endl;
    cout << "Current Top Element: " << st.top() << endl; // টপ ভ্যালু দেখাবে
    cout << "-----------------------" << endl;

    cout << "Popping elements (LIFO order): ";
    while(!st.empty()) {
        cout << st.pop() << " "; // একটা একটা করে বের করে প্রিন্ট করবে
    }
    cout << endl;

    return 0;
}