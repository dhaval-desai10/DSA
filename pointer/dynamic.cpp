#include<iostream>
using namespace std;
int main()
{
    // 1D array 
    int n;
    cout<<"Enter : ";
    cin>>n;
    int *arr;
    arr =new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<< arr[i] <<" ";
    }
    cout<<endl<<endl;
    //for deleting the memory 
    delete [] arr;

    // 2D array
    int m,p;
    cout<<"Enter : ";
    cin>>m>>p;
    int **arr2;
    arr2 = new int*[m];
    for(int i=0;i<m;i++)
    {
        arr2[i] = new int[n];
        }   
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<p;j++)
            {
                cin>>arr2[i][j];

            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<p;j++)
            {
                cout<<arr2[i][j]<<" ";
            }
            cout<<endl;
        }
       // for deleting memory in 2D array is
       for(int i=0;i<m;i++)
       {
        delete [] arr2[i];
        }
        delete [] arr2;
        


 return 0;
}