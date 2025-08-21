
// linear searching in 2D array :
#include<iostream>
using namespace std;
int main()
{
    int arr[3][3];
    cout<<"enter : "<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"array : "<<endl;
     for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i] [j] <<" ";
        }
        cout<<endl;
    }
    int target ;
    cout<<" target is : ";
    cin>>target;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==target)
            {
                cout<<"Element is found  : "<<target <<endl;
            }

        }
    }

   
     
 return 0;
}