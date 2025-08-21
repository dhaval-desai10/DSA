// #include <bits/stdc++.h>
// using namespace std;
// int squareroot(int n, int low, int high)
// {
//     int result = 0;
//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         if (mid * mid <= n)
//         {
//             result = mid;
//             low = mid + 1;
//         }
//         else
//             high = mid - 1;
//     }
//     return result;
// }
// int main()
// {
//     int n = 28;
//     int low = 1;
//     int high = n;
//     cout << squareroot(n, low, high) << endl;
//     return 0;
// }

//  // find the Nth root of the M number

// #include <bits/stdc++.h>
// using namespace std;

// // Function to calculate mid^n without using pow()
// long long power(int base, int exp)
// {
//     long long result = 1;
//     for (int i = 0; i < exp; i++)
//     {
//         result *= base;
//     }
//     return result;
// }

// int nthroot(int n, int m, int low, int high)
// {
//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         long long midPowerN = power(mid, n);

//         if (midPowerN == m)
//         {
//             return mid;
//         }
//         else if (midPowerN > m)
//             high = mid - 1;
//         else
//             low = mid + 1;
//     }
//     return -1;
// }
// int main()
// {
//     int n = 3;
//     int m = 27;
//     int low = 1;
//     int high = m;
//     cout << nthroot(n, m, low, high) << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10] = {3, 6, 1, 10, 2};
    int n = 5;
    int maxinumber = -1;
    for (int i = 0; i < n; i++)
    {
        maxinumber = max(maxinumber, arr[i]);
        int ind = i;
        reverse(arr[0],arr[ind]);

    }
    cout<<maxinumber<<endl;
    
    return 0;
}