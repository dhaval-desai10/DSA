
// // 1D Dp problems
// //  how to recognize its Dp
// // try all possible ways where needed (recursion)----> or the best ways
// // ---> count the total number of ways

// // fibonacci

// // recursion to dp

#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

//  //tabulation solution of the fibonaccie series recursion to tabulation form

void fibo_table(int n)
{
    // // insted of using this extra space thinking diffrent to reduce the SC
    // int dp[100];
    // dp[0] = 0;
    // dp[1] = 1;
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        // dp[i] = dp[i - 1] + dp[i - 2];
        int curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    cout << "dp table : " << prev1 << endl;
}

// // frog jump  memoization and tabulation solution check

int frog(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    int right = INT_MAX;
    int left;
    if (dp[n] != -1)
        return dp[n];
    left = frog(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    if (n > 1)
        right = frog(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    return dp[n] = min(left, right);
}

int frog_k_jump(int n, vector<int> &heights, vector<int> &dp, int k)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ministep = INT_MAX;

    for (int i = 1; i <= k; i++)
    {

        int jump;
        if (n - i >= 0)
        {
            jump = frog_k_jump(n - i, heights, dp, k) + abs(heights[n] - heights[n - i]);
        }
        ministep = min(jump, ministep);
    }
    return dp[n] = ministep;
}

int maximum_sum_nonAdjacent(vector<int> &arr, int n)
{
    // // add dp in this 
    if (n == 0)
    {
        return arr[0];
    }
    if (n < 0)
    {
        return 0;
    }
    int pick = arr[n] + maximum_sum_nonAdjacent(arr, n - 2);
    int notpick = 0 + maximum_sum_nonAdjacent(arr, n - 1);
    return max(pick, notpick);
}



int main()
{
    // // 1.
    // int  n;
    // cin >> n;
    // vector<int> dp(n + 1, -1);
    // cout << f(n, dp) << endl;
    // fibo_table(n);

    // // 2.
    // int n = 6;
    // vector<int> heights = {30, 10, 60, 10, 60, 50};
    // //  // vector<int> dp(n, -1);
    // // // cout << "frog jump energy min :" << frog(n - 1, heights, dp) << endl;
    // //  // dp[n] = {0};
    // // //  dp[0] = 0;
    // int prev1 = 0;
    // int cur;
    // int prev2 = 0;
    // for (int i = 1; i < n; i++)
    // {
    //     int right = INT_MAX;
    //     // //   int left = dp[i - 1] + abs(heights[i - 1] - heights[i]);
    //     //  //  if (i > 1)
    //     //  //     right = dp[i - 2] + abs(heights[i - 2] - heights[i]);
    //     // //  dp[i] = min(left, right);
    //     // // space optimzation
    //     int left = prev1 + abs(heights[i - 1] - heights[i]);
    //     if (n > 1)
    //         right = prev2 + abs(heights[i - 2] - heights[i]);
    //     cur = min(left, right);
    //     prev2 = prev1;
    //     prev1 = cur;
    // }
    // //  // cout << "tabulation : " << dp[n - 1] << endl;
    // cout << "tabulation : " << prev1 << endl;

    // // 3.
    // int n = 6;
    // vector<int> heights = {30, 10, 60, 10, 60, 50};
    // vector<int> dp(n, -1);
    // cout << "frog_jump(K) energy min :" << frog_k_jump(n - 1, heights, dp, 5) << endl;

    // // 4.
    vector<int> arr = {2, 1, 4, 9};
    cout << "maxisum nonAdjacent taken element : " << maximum_sum_nonAdjacent(arr, 3) << endl;

    return 0;
}
