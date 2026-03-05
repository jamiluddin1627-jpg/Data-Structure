#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> heap;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        heap.push_back(x);
        int current = heap.size() - 1;
        while(current > 0)
        {
            int parent = (current - 1) / 2;
            if(heap[parent] < heap[current]) swap(heap[parent], heap[current]);
            else break;
            current = parent;
        }
    }
    for(int j = 0; j <heap.size(); j++)
    {
        cout << heap[j] << " ";
    }
    return 0;
}