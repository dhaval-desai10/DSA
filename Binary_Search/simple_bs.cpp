// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[100] = {1, 2, 4, 6, 7, 8, 9};
//     int n = 7;
//     int target = 8;
//     int low = 0;
//     int high = n - 1;
//     int mid = (low + high) / 2;

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         if (arr[mid] == target)
//         {
//             cout << "target found : " << mid << endl;
//             break;
//         }
//         else if (arr[mid] < target)
//         low = mid + 1;
//         else
//         high = mid - 1;
//     } 

//     return 0;
// }

// finding the lower of bound of the any element 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100] = {1, 2, 4, 6, 7, 8, 9};
    int n = 7;
    int target = 5;
    int low= 0,high = n-1;
    int ans;

    while(low <=high)
    {
        int mid = (low + high) / 2;
        // if(arr[mid] > target)  // for upper bound of any target 
        if(arr[mid] >= target)   // for lower bound 
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout<<"result : "<<ans<<endl;

    
 return 0;
}