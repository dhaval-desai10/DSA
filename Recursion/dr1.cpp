//  binary search using recusion 

#include<iostream>
using namespace std;
int binary_search(int arr[],int low,int high,int key)
{
    if(low>high)
    {
        return -1;
    }
    int mid = (low+high)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key)
    {
        return binary_search(arr,low,mid-1,key);
    }
    else
    {
        return binary_search(arr,mid+1,high,key);
    }
}
int main()
{
    int arr[5] = {2,3,5,7,8};
    int key = 5;
    int low = 0;
    int high = 4;
    int result = binary_search(arr,low,high,key);
    if(result==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Element found at index : "<<result<<endl;
    }
    
 return 0;
}