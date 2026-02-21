#include <bits/stdc++.h> 
using namespace std;
 
string kevinStackProblem(string &s)
{
    stack<char> st;
    
    // ধাপ ১: মূল স্ট্রিংয়ের প্রতিটি ক্যারেক্টার স্ট্যাকে পুশ করা
    for(int i = 0; i < (int)s.length(); i++) {
        st.push(s[i]);
    }
    
    string ns = ""; // নতুন একটি খালি স্ট্রিং নিলাম
    
    // ধাপ ২: স্ট্যাক থেকে টপ এলিমেন্ট নিয়ে নতুন স্ট্রিংয়ে যোগ করা এবং পপ করা
    while(!st.empty()) {
        ns += st.top(); // টপ এলিমেন্টটি ns-এ যোগ করছি
        st.pop();       // এরপর সেটি স্ট্যাক থেকে ফেলে দিচ্ছি
    }
    
    return ns; // রিভার্স করা নতুন স্ট্রিংটি রিটার্ন করছি
}

int main() {
    int t;
    // টেস্ট কেসের সংখ্যা ইনপুট নিচ্ছি
    if (cin >> t) {
        while (t--) {
            string s;
            cin >> s; // স্ট্রিং ইনপুট নিচ্ছি
            
            // ফাংশন কল করে সরাসরি আউটপুট প্রিন্ট করছি
            cout << kevinStackProblem(s) << endl;
        }
    }
    return 0;
}