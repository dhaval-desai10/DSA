// bucket sort 
// Time complexity: O(n)
// Space complexity: O(n)
// where n is the number of elements in the input array
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    int bucket[max+1] = {0};
    for(int i=0;i<n;i++)
    {
        bucket[arr[i]]++;
    }
    int index = 0;
    for(int i=0;i<max+1;i++)
    {
        while(bucket[i]>0)
        {
            arr[index++] = i;
            bucket[i]--;
        }
    }
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
 return 0;
}
