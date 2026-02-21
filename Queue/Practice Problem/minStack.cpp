#include <iostream>
#include <stack>

using namespace std;

class minStack {
    stack<int> st;
    stack<int> minSt;
    
public:
    minStack() {}
    
    void push(int num) {
        st.push(num);
        if(minSt.empty() || num <= minSt.top()) {
            minSt.push(num);
        } else {
            minSt.push(minSt.top());
        }
    }
    
    int pop() {
        if(st.empty()) return -1;
        int topVal = st.top();
        st.pop();
        minSt.pop();
        return topVal;
    }
    
    int top() { 
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(minSt.empty()) return -1;
        return minSt.top();
    }
};

int main() {
    minStack s;

    cout << "--- Testing MinStack ---" << endl;

    // ১. ভ্যালু পুশ করা হচ্ছে
    s.push(2);
    cout << "Pushed: 2, Current Min: " << s.getMin() << endl;

    s.push(3);
    cout << "Pushed: 3, Current Min: " << s.getMin() << endl;

    s.push(2);
    cout << "Pushed: 2,  Current Min: " << s.getMin() << endl;

    s.push(1);
    cout << "Pushed: 1,  Current Min: " << s.getMin() << endl;

    cout << "\n--- Checking Pop Operations ---" << endl;

    // ২. চেক করা হচ্ছে পপ করার পর মিনিমাম ঠিক থাকে কি না
    cout << "Top element: " << s.top() << endl; // ১ হওয়া উচিত
    cout << "Popped: " << s.pop() << ", New Min: " << s.getMin() << endl; // মিনিমাম ২ থাকা উচিত

    cout << "Popped: " << s.pop() << ", New Min: " << s.getMin() << endl; // ২ পপ হবে, মিনিমাম ৩ হয়ে যাবে
    
    cout << "Final Min: " << s.getMin() << endl;

    return 0;
}