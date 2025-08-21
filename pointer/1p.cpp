#include<iostream>
using namespace std;
int main()
{
    // int n=5;
    // cout<< n << endl << &n << endl; 
    // int *ptr=&n;
    // cout<< *ptr <<endl;
    // cout<<" size of integer "<<sizeof(n)<<endl;
    // cout<<" size of pointer "<<sizeof(ptr)<<endl;
    // int i=9;
    // int *p=&i;
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // int *q=0;
    // q=&i;//**************imp  */
    // cout<< q<<endl;
    // cout<<*q<<endl;

    int num=7;
    int *ptr=&num;
    cout<<"before number : "<< num <<endl;
    (*ptr)++ ;// *ptr++ both are different .

    cout<<"after number  : "<< num <<endl;

    // copying of pointer

    int  *q=ptr;

    cout<<"ptr "<<ptr<<" - "<<q<<endl; 
    cout<<"*ptr "<<*ptr<<" - "<<*q<<endl;

    int i=3;
    int *t=&i;
    // cout<< *t++ <<endl;
    *t=*t+1;
    cout<< *t <<endl;
    cout<<" t "<< t <<endl;
    t=t+1;
    cout<<" t is "<<t <<endl;
    cout<<endl;


 return 0;
}