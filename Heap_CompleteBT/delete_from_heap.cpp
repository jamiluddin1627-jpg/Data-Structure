#include<bits/stdc++.h>
using namespace std;
void insert_in_heap(vector<int> &heap, int x)
{
    heap.push_back(x);
    int current = heap.size() - 1;
    while(current > 0)
    {
        int parent = (current - 1) / 2;
        if(heap[parent] < heap[current])
        {
            swap(heap[parent], heap[current]);
            current = parent;
        }
        else
        {
            break;
        }
    }
}
void delete_from_heap(vector<int> &v)
{
    if(v.empty()) return;
    swap(v[0], v[v.size() - 1]);
    v.pop_back();
    int current = 0;
    while(true)
    {
        int left_idx = 2 * current + 1;
        int right_idx = 2 * current + 2;
        int largest = current; 
        if(left_idx < v.size() && v[left_idx] > v[largest]) largest = left_idx;
        if(right_idx < v.size() && v[right_idx] > v[largest]) largest = right_idx;
        if(largest == current) break;
        swap(v[current], v[largest]);
        current = largest;  
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert_in_heap(v, x);
    }
    for(int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    delete_from_heap(v);
    for(int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}