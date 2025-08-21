// merge two sorted 

#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    cout<<"Enter the size of first array : ";
    cin>>n1;
    int arr1[n1];
    cout<<"Enter the elements of first array : ";
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the size of second array : ";
    cin>>n2;
    int arr2[n1];
    cout<<"Enter the elements of second array : ";
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    int arr3[n1+n2];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k]=arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k]=arr2[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    cout<<"two sorted merged array is : "<<endl;
    for(int i=0;i<n1+n2;i++)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
 return 0;
}