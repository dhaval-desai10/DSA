#include<iostream>
using namespace std;
int main()
{
    // int arr[3]={1,23,44};
    // char ch[7]="dhaval";
    // // printing -->  address of arr
    // cout<< "  :: "<<arr <<endl;
    // printing --> dhaval not address 
    // cout<< "  :: "<<ch <<endl;
    // char *c=&ch[0];
    // cout<< "  :: "<<&c <<endl;
    int value = 5;
    int *ptr = &value;
    cout<< "  :: "<< ptr <<endl;
    ptr=ptr+1;
    // *ptr=*ptr+1;
    cout<< "  :: "<< ptr <<endl;




    
 return 0;
}