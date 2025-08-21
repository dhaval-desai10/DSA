#include <bits/stdc++.h>
using namespace std;


//  //using linear seaching 

// int maxino_1_row(vector<vector<int>> &arr, int row, int col)
// {
//     int max = INT_MIN;
//     int ind = -1;
//     for (int i = 0; i < row; i++)
//     {
//         int countrow = 0;
//         for (int j = 0; j < col; j++)
//         {
//             countrow += arr[i][j];
//         }
//         if (countrow > max)
//         {
//             max = countrow;
//             ind = i;
//         }
//     }
//     return ind;
// }

int lower_bound(vector<int> arr)
{
    int low = 0,high = arr.size() - 1;
    int ans;
    while(low <= high)
    {
        int mid = (high + low) >> 1;
        if(arr[mid] >= 1){
            ans = mid;
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int finalans(vector<vector<int>> arr)
{
    int count_max = -1;
    int ind = -1;
    for(int i = 0; i < arr.size(); i++)
    {
        int count = arr[i].size() - lower_bound(arr[i]);
        if(count > count_max) {
            count_max = count;
            ind = i;
        }
    }
    return ind;
}

int main()
{
    // input having all rows 0 or 1 with sorted order
    vector<vector<int>> arr = {
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1}};
    int n = arr.size();
    int m = arr[0].size(); 
    // cout<<maxino_1_row(arr, n, m)<<endl;
    cout<<finalans(arr)<<endl;

    return 0;
}