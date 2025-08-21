//  --->using recursion <---
// 1. array is sorted or not. 
// 2.sum of array.
// 3. linear searching .
// 4. binary searching.



//  1.-------------------------------------------------------------------------//
// #include<iostream>
// using namespace std;
// bool sorted(int arr[],int size)
// {
//     // base case 
//     if(size==1 || size==0)
//     {
//         return true;
//     }
//     // recursive case
//     else 
//     {
//         if(arr[0]>arr[1])
//         {
//             return false ;
//         }
//         else {
//             return sorted(arr+1,size-1);  
            
//         }
//     }
// }
 
// int main()
// {
//     int arr[5]={2,3,4,5,6};
//     int size = 5;
//    bool ans=  sorted(arr,size);
// //    cout<<"result is : "<< ans << endl;
// if(ans)
// {
//     cout<<"sorted"<<endl;
// }
// else
// {
//     cout<<"not sorted"<<endl;
// }
//  return 0;
// }
// 2. ------------------------------------------------------------------
// #include<iostream>
// using namespace std;
// int getsum(int arr[],int n)
// {
//     if(n==0)
//     {
//         return 0;
    
//     }
//     if(n==1)
//     {
//         return arr[0];
//     }
//     int sum = arr[0] + getsum(arr + 1,n-1);
//     return sum;
// } 
   
// int main()
// {
//     int arr[5]={1,2,3,4,5};
//     int size = 5;
//     int ans = getsum(arr,size);
//     cout<< ans <<endl;
//  return 0;
// }
// 3. ------------------------------------------------------------------

// #include<iostream>
// using namespace std;
// bool linearsearching(int arr[],int size,int target )
// {
//     if(size==0)
//     {
//         return false ;
//     }
//     if(arr[0]==target)
//     {
//         return true ;
//     }
    // int ans = linearsearching(arr+1,size-1,target);
    // if(ans==-1)
    // {
    //     return false;
    // }
    // return true;  // return linearsearching(arr+1,size -1 ,target )

// }
// int main()
// {
//     int arr[5]={2,5,7,8,9};
//     int size =5;
//     int target;
//     cout<<"enter target : ";
//     cin>>target ;
//     int ans = linearsearching(arr,size,target);
//     if(ans)
//     {
//         cout<<"element is found "<<endl;
//     }
//     else {
//         cout<<"element is not found "<<endl;
//     }
//  return 0;
// }
// 4. ------------------------------------------------------------------

#include<iostream>
using namespace std;
bool binarysearching(int arr[],int mid ,int target ,int size )
{
    if(size==0)
    {
        return false ;

    }
    if(arr[mid]==target)
    {
        return true ;

    }
    if(arr[mid]<target)
    {
        return binarysearching(arr,mid+1,target,size);
        
    }
    else {
        return binarysearching(arr,mid-1,target,size);

    }
    


}
int main()
{
    int arr[5]={2,4,5,7,8};
    int size =5;
    int target;
    cout<<"enter target : ";
    cin>>target ;
    int mid = size/2;
    int ans = binarysearching(arr,mid,target,size);
    if(ans)
    {
        cout<<"element is found "<<endl;
    }
    else {
        cout<<"element is not found "<<endl;
    }

 return 0;
}
