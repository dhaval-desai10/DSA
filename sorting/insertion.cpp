// time complexity
// best case : O(n)
// worst case : O(n^2)
// space complexity : O(n)

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of an array : ";
    cin >> n;
    int arr[100];
    cout << "Enter the array elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// recursive
// time complexity
// best case : O(n)
// worst case : O(n^2)
// space complexity : O(n)

// #include<iostream>
// using namespace std;
// void insert(int arr[],int size)
// {
//     if(size<=1)
//     {
//         return;
//     }
//     insert(arr,size-1);
//     int key = arr[size-1];
//     int j = size - 2;

//     while(j>=0 && arr[j]>key)
//     {
//         arr[j+1] = arr[j];
//         j--;
//     }
//     arr[j+1] = key;
//     return;
// }
// int main()
// {
//     int n;
//     cout<<"Enter the size of an array : ";
//     cin>>n;
//     int arr[n];
//     cout<<"Enter the array elements : "<<endl;
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     insert(arr,n);
//     cout<<"sorted array using recursive call is : "<<endl;
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";

//     }
//     cout<<endl;
//  return 0;
// }
