// insertion sort using recursin 

#include<iostream>
using namespace std;
void insertionsort(int arr[],int size)
{
    if(size<=1)
    {
        return;

    }
    insertionsort(arr,size-1);
    int key=arr[size-1];
    int j=size-2;
    while(j>=0 && arr[j]>key)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
    return;
    
    }
int main()
{
    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertionsort(arr,n);
    cout<<"Sorted array is : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
   

}