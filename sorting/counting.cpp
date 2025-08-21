// // counting sort 
// // Time complexity: O(n)
// // Space complexity: O(n)
// // where n is the number of elements in the input array
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter the number of elements: ";
//     cin >> n;
//     int arr[n];
//     cout << "Enter the elements: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int max = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     int count[max + 1] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         count[arr[i]]++;
//     }
//     int index = 0;
//     for (int i = 0; i < max + 1; i++)
//     {
//         while (count[i] > 0)
//         {
//             arr[index++] = i;
//             count[i]--;
//         }
//     }
//     cout << "Sorted array is: ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }


#include<iostream>
using namespace std;
void countingsort(int arr[],int n,int key){
    int count[key+1]={0};
    int output[n];
    for(int i=0;i<n;i++){
        count[arr[i]]++;

    }
    for(int i=1;i<=key;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;

    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }

}
int main()
{
    int n = 10;
    int arr[n] = {4, 2, 2, 8, 3,9,10,6,4,5};
   
    int k=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>k)
        {
            k=arr[i];
        }
    }
    countingsort(arr,n,k);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

 return 0;
}

