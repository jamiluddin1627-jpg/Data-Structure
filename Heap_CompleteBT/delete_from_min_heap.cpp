#include<bits/stdc++.h>
using namespace std;
void insert_in_heap(vector<int> &heap, int x)
{
    heap.push_back(x);
    int current = heap.size() - 1;
    while(current > 0)
    {
        int parent = (current - 1) / 2;
        if(heap[parent] > heap[current])
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
        int last_idx = v.size() - 1;
        
        if( left_idx<= last_idx && right_idx <= last_idx)
        {
            if(v[left_idx] <= v[right_idx] && v[left_idx] < v[current])
            {
                swap(v[left_idx], v[current]);
                current = left_idx;
            }
            else if(v[right_idx] < v[current])
            {
                swap(v[right_idx], v[current]);
                current = right_idx;
            }
            else
            {
                break;
            }
        }
        else if(left_idx <= last_idx)
        {
            if(v[left_idx] < v[current])
            {
                swap(v[left_idx], v[current]);
                current = left_idx;
            }
            else
            {
                break;
            }
        }
        else if(right_idx <= last_idx)
        {
            if(v[right_idx] < v[current])
            {
                swap(v[right_idx], v[current]);
                current = right_idx;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}
void print_heap(vector<int> v)
{
    for(int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
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
    print_heap(v);
    delete_from_heap(v);
    print_heap(v);
    cout << endl;
    return 0;
}