#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5, 1, 4, 3, 2};
     
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Before Sorting: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
      
// Selection Sort
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n ; j++)
        {
            if(arr[i] > arr[j])
            {
               int temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
            }
            for(int k = 0; k < n; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
        cout<<i<<" Iteration completed"<<endl;
    }
    cout << "After Selection Sort: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
cout << endl;
cout<<"\n+++===============================================+++"<<endl;
// Bubble Sort
    int arr2[] = {5, 1, 4, 2, 3};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);  

    cout << "\nBefore Sorting: ";
    for(int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    cout << "Sorting in Progress: " << endl;
    for(int i = 0; i < n2-1; i++)
    {
        for(int j = 0; j < n2-i-1; j++)
        {
            if(arr2[j] > arr2[j+1])
            {
                int temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
 
            }
            
            for(int k = 0; k < n2; k++)
            {
                cout << arr2[k] << " ";
            }
            cout << endl;
        }
        cout<<i<<" Iteration completed"<<endl;
    }
    cout << "After Bubble Sort: ";
    for(int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}