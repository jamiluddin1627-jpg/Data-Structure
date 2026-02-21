#include <bits/stdc++.h>
using namespace std;

class myQueue {
public:
    stack<int> st;

    myQueue() {
        // Constructor
    }
    
    // Push operation: O(1)
    void push(int x) {
        st.push(x);
    }
    // Pop operation: O(N)
    int pop() {
        stack<int> newSt;
        int last;
        
        // সব এলিমেন্ট নতুন স্ট্যাকে পার করছি, শেষেরটা বাদে
        while(!st.empty())
        {
            int k = st.top();
            st.pop();
            
            if(st.empty())
            {
                last = k; // এটাই শেষের এলিমেন্ট (যেটা ডিলিট হবে)
                break;    // এটাকে newQ তে আর পুশ করব না
            }
            newSt.push(k);
        }
        st = newSt; // মেইন স্ট্যাক আপডেট করলাম
        return last;
    }
    
    // Top operation: O(N)
    int top() {
        stack<int> newSt;
        int last;
        
        while(!st.empty())
        {
            int k = st.top();
            st.pop();
            
            if(st.empty())
            {
                last = k; // এটাই শেষের এলিমেন্ট (Stack Top)
            }
            newSt.push(k); // টপ দেখার সময় এলিমেন্ট হারানো যাবে না, তাই সব পুশ করছি
        }
        
        st = newSt; // মেইন স্ট্যাক আপডেট করলাম
        return last;
    }
    
    bool empty() {
        return st.empty();
    }
};

int main() {
    myQueue q;
    
    int n;
    cout << "How many elements?"<<endl;
    cin >> n;
    
    cout << "Enter the elements to push onto the stack: "<<endl;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }
    
    cout << "\n-----------------------" << endl;
    cout << "Current Top Element: " << q.top() << endl; // টপ ভ্যালু দেখাবে
    cout << "-----------------------" << endl;

    cout << "Popping elements (LIFO order): ";
    while(!q.empty()) {
        cout << q.pop() << " "; // একটা একটা করে বের করে প্রিন্ট করবে
    }
    cout << endl;

    return 0;
}