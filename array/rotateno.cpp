#include<iostream>
using namespace std;
int main()
{
    int arr[6]={1,2,3,4,5,6};
    cout<<"Enter the number to rotate : ";
    int n;
    cin>>n; 
    int j=0,k=0;
    int arrf[6];
    for(int i=6-n;i<6;i++)
    {
        k=arr[i];
        arrf[j]=k;
        j++;
    }   
    for(int i=0;i<6-n;i++)
    {
     k=arr[i];
     arrf[j]=k; 
     j++;
    }
    
    for(int i=0;i<6;i++)
    {
        cout<<arrf[i]<<" ";
    }
    
   

 return 0;
}
// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int count=0;
//         for(int i=1;i<nums.size();i++)
//         {
//             if(nums[i-1]>nums[i])
//             {
//                 count++;
//             }
//         }
//         if(nums[nums.size()-1]>nums[0])
//         count++;
//         return count<=1;
        
//     }
// };   