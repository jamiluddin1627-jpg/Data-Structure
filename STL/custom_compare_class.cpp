#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
     string name;
     int roll;
     int marks;
        Student(string name,int roll,int marks)
        {
            this->name = name;
            this->roll = roll;
            this->marks = marks;
        }
};

class Compare
{
    public:
    bool operator()(Student a,Student b)
    {
        if(a.marks == b.marks)
        {
            return a.roll > b.roll; // Ascending order of roll number
        }
        return a.marks < b.marks; // Descending order of marks
    }
};

int main()
{
    int n;
    cin>> n;
    priority_queue<Student,vector<Student>,Compare> pq;
    for(int i=0;i<n;i++)
    {
        string name;
        int roll,marks;
        cin>>name>>roll>>marks;
        Student obj(name,roll,marks);
        //cout<<obj.name<<" "<<obj.roll<<" "<<obj.marks<<"\n";
        pq.push(obj);
    }
    cout<<"Students in priority order:\n";
    while(!pq.empty())
    {
        Student s = pq.top();
        cout<<s.name<<" "<<s.roll<<" "<<s.marks<<"\n";
        pq.pop();
    }
    return 0;
}