#include<iostream>
using namespace std;
int main()
{
    int arr[10]={10,20,30};
    // cout<<" address  : "<<arr<<endl;
    // cout<<" address  : "<<&arr[1]<<endl;

    //adifati  he 

    int i=2;  //-->30
    // cout<<i[arr]<<endl; // ********
    // cout<<*(arr+i)<<endl; // ********
    // cout<<*(arr+2)<<endl; // ********
    cout<<"address arr : "<< &arr<<endl;
    int *p=&arr[0];
    cout<<"address p : "<<& p <<endl;

 return 0;
} 