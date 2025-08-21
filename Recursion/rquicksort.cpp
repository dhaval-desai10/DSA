#include<iostream>
using namespace std;

int partition(int arr[],int s,int e)
{
    int pivot=arr[e];
    int pindex=s;
    for(int i=s;i<e;i++)
    {
        if(arr[i]<=pivot)
        {
            int temp;
            temp=arr[i];
            arr[i]=arr[pindex];
            arr[pindex]=temp;
            pindex++;
        }
    }
    int temp;
    temp=arr[pindex];
    arr[pindex]=arr[e];
    arr[e]=temp;
    return pindex;

}
void quicksort(int arr[],int s,int e)
{
    if(s<=e)
    {
        return;
    }
    int p= partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);

}
int main()
{
    int arr[5]={1,3,6,8,4};
    int n=5;
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
   

 return 0;
}