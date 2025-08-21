// Recursion String 
// 1. reverse of string using racursion. and simple reverse using the loop .
//
// #include<iostream>
// using namespace std;
// void reversestring(string str,int size)
// {
//     int i=0,j=size-1;
//     while(i<j)
//     {
//         swap(str[i],str[j]);
//         i++;
//         j--;

//     }
//     cout<<str<<endl;

// }
// int main()
// {
//     string str="DHAVAL";
//     reversestring(str,str.size());

//  return 0;
// }
#include<iostream>
using namespace std;
bool reversestring(string str,int i,int j )
{

    // if(size==0)
    // {
    //     return ;
    // }
    // if ( size ==1)
    // {
    //     cout<< str[0] <<endl;
    // }
    // else
    // {
    //     cout<<str[size-1];
    //     reversestring(str,size-1);
    //     }
    if(i>j)
    {
        return true;
    }
    if(str[i]!=str[j])
    {
        return false ;

    }
    else {
        return reversestring(str,i+1,j-1);
    }
    
    
}
int main()
{
    string str="Dhaval";
    int i=0,j=str.size()-1;
    int ans = reversestring(str ,i,j);
    cout<<ans <<endl;

    cout<<endl;
 return 0;  
}