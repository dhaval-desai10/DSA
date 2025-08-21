//selection sort
#include<iostream>
using namespace std;
int main()
{
      // int n=5;
      // int arr[5]={10,44,33,99,2};
      int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
      
       for(int i=0;i<n-1;i++)
       {
            int minindex=i;
            for(int j=i+1;j<n;j++)
            {
                  if(arr[j]<arr[minindex])
                  minindex=j;
            }
            //      swap(arr[minindex],arr[i]);
            int temp=arr[minindex];
            arr[minindex]=arr[i];
            arr[i]=temp;
       }

       for(int i=0;i<n;i++)
       {
            cout<<arr[i]<<" ";
       }
}
