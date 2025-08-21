#include <bits/stdc++.h>
using namespace std;

//  // 1. constant window problems
void const_window(vector<int> arr, int n, int k)
{
    int l = 0;
    int r = k - 1;
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;
    while (r < n - 1)
    {
        sum -= arr[l];
        l++;
        r++;
        sum += arr[r];
        cout << sum << endl;
    }
}

// // 2. longest subarray/subtring where <conditions is there>
// longest subarray with sum <= k
// // generating all then check
// void longest_subarray(vector<int> arr, int n, int k)
// {
//     int a = -1, b = -1;
//     int maxln = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if (sum <= k)
//             {
//                 if (j - i + 1 > maxln)
//                 {
//                     maxln = j - i + 1;
//                     a = i;
//                     b = j;
//                 }
//             }
//             else if (sum > k)
//             {
//                 break;
//             }
//         }
//     }
//     cout << "maxlength : " << maxln << endl;
//     cout << "a" << a << " b" << b << endl;
//     for (int ar = a; ar <= b; ar++)
//     {
//         cout << arr[ar] << " ";
//     }
//     cout << endl;
// }
// // better approach for this
void longest_subarray(vector<int> arr, int n, int k)
{
    // // window having two pointer
    //  expand - right  , shrink -- left
    int sum = 0, maxlen = 0;
    int l = 0;
    int r = 0;
    while (r < n)
    {
        sum += arr[r];
        while (sum > k)
        { // here if(sum > k) work also
            sum -= arr[l];
            l++;
        }
        if (sum <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    // // optimize  use if condition insted of using inner while
    cout << "maxlength : " << maxlen << endl;
}

// // 3. finding the number of the subarray
// // 4. finding the minimum/shortest  window <condition> rare

int fruits_into_basket(vector<int> arr)
{
    int l = 0;
    int r = 0;
    int n = arr.size();
    int maxilen = 0;
    unordered_map<int, int> freq;
    // while (r < n)
    {
        freq[arr[r]]++;
        if (freq.size() > 2)
        {
            while (freq.size() > 2)
            {
                freq[arr[l]]--;
                if (freq[arr[l]] == 0)
                {
                    freq.erase(arr[l]);
                }
                l++;
            }
        }
        if (freq.size() <= 2)
        {
            maxilen = max(maxilen, r - l + 1);
        }
        r++;
    }

    while (r < n)
    {
        freq[arr[r]]++;
        if (freq.size() > 2)
        {
            freq[arr[l]]--;
            if (freq[arr[l]] == 0)
            {
                freq.erase(arr[l]);
            }
            l++;
        }
        if (freq.size() <= 2)
        {
            maxilen = max(maxilen, r - l + 1);
        }
        r++;
    }
    return maxilen;
}

int main()
{
    vector<int> arr = {1, 2, 2, 3, 3, 4, 4};
    int n = arr.size();
    int k = 9;
    // // 1.
    // const_window(arr, n, k);

    // // 2.
    // longest_subarray(arr, n, k);

    // // fruits in basket
    // cout << fruits_into_basket(arr) << endl;

    

    return 0;
}