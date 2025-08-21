#include<iostream>
using namespace std;
int main()
{
    int arr[7]={2,0,5,0,4,0,0};
    int i=0;
   
        for(int j=0;j<7;j++)
        {
            if(arr[j]!=0)
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }
        }
        for(int i=0;i<7;i++)
        {
            
            cout<<arr[i]<<" ";

        }
    

 return 0;
}