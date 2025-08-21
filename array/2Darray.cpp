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
    cout<<"sum of row : "<<endl;

    for(int i=0;i<3;i++)
    {
    int sum1=0;
        for(int j=0;j<3;j++)
        { 
        sum1+=arr[i][j];
        }
    cout<<sum1<< " ";
    }cout<<endl;
    cout<<"coloumn wise sum : "<<endl;

    for(int j=0;j<3;j++)
    {
    int sum1=0;
        for(int i=0;i<3;i++)
        {
        sum1+=arr[i][j];
        }
    cout<<sum1<< " ";
    }
     
 return 0;
}