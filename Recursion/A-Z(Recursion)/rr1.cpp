#include <bits/stdc++.h>
using namespace std;

void fn(int i, int n)
{
    // // recursion
    // if (i > n)
    // {
    //     return;
    // }
    // cout << "hey " << i << endl;
    // recursion call its i + 1
    // fn(i + 1, n);

    // if we want to use *backtraking* pring execute after function calling

    if (i < 1)
    {
        return;
    }
    fn(i - 1, n);
    cout << "hey " << i << endl;
}

// void sumofn(int i, int sum)
// {
//     if (i < 1)
//     {
//         cout << sum << endl;
//         return;
//     }
//     sumofn(i - 1, sum + i);
// }

int sumofn(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sumofn(n - 1);
}

// void reversearray(int arr[], int l, int r)
// {
//     if (l >= r)
//     {
//         return;
//     }
//     swap(arr[l], arr[r]);
//     reversearray(arr, l + 1, r - 1);
// }

void reversearray(int arr[], int i)
{
    int n = 5;
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    reversearray(arr, i + 1);
}

bool stringpali(const string &s, int i)
{
    if (i >= s.length() / 2)
        return true;
    if (s[i] != s[s.length() - i - 1])
        return false;
    return stringpali(s, i + 1);
}

// void fibonacci(int n)
// {
//     int fibo[100];
//     fibo[0] = 0;
//     fibo[1] = 1;
//     for (int i = 2; i < n; i++)
//     {
//         fibo[i] = fibo[i - 1] + fibo[i - 2];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << fibo[i] << " ";
//     }
// }

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void print_subsequence(int i, vector<int> arr, vector<int> ans)
{
    if (i == arr.size())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(arr[i]); // take it
    print_subsequence(i + 1, arr, ans);
    ans.pop_back(); // remove it
    print_subsequence(i + 1, arr, ans);
}

void sum_isK_subsequence(int i, vector<int> arr, vector<int> ans, int sum, int sumK, bool &found)
{
    // if want to print all sequence then removing this flag condition
    if (found)
        return; // stop recursion if already found
    if (i == arr.size())
    {
        if (sum == sumK)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
            found = true; // set flag
        }
        return;
    }
    ans.push_back(arr[i]);
    sum_isK_subsequence(i + 1, arr, ans, sum + arr[i], sumK, found);
    ans.pop_back();
    sum_isK_subsequence(i + 1, arr, ans, sum, sumK, found);
}

// void merge(vector<int> &arr, int low, int mid, int high)
// {
//     vector<int> ans;
//     int left = low;
//     int right = mid + 1;
//     while (left <= mid && right <= high)
//     {
//         if (arr[left] <= arr[right])
//         {
//             ans.push_back(arr[left]);
//             left++;
//         }
//         else
//         {
//             ans.push_back(arr[right]);
//             right++;
//         }
//     }
//     while (left <= mid)
//     {
//         ans.push_back(arr[left]);
//         left++;
//     }
//     while (right <= high)
//     {
//         ans.push_back(arr[right]);
//         right++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         arr[i] = ans[i - low];
//     }
// }
// void mergesort(vector<int> &arr, int low, int high)
// {
//     if (low >= high)
//         return;
//     int mid = (low + high) / 2;
//     mergesort(arr, low, mid);
//     mergesort(arr, mid + 1, high);
//     merge(arr, low, mid, high);
// }

// int partition(vector<int> &arr, int low, int high)
// {
//     int pivot = arr[low];
//     int left = low + 1;
//     int right = high;
//     for (int i = left; i <= high; i++)
//     {
//         if (arr[i] < pivot)
//         {
//             swap(arr[i], arr[left]);
//             left++;
//         }
//     }
//     swap(arr[left - 1], arr[low]);
//     return left - 1;
// }
//     void quicksort(vector<int> & arr, int low, int high)
//     {
//         if (low >= high)
//         {
//             return;
//         }
//         int pivot = partition(arr, low, high);
//         quicksort(arr, low, pivot - 1);
//         quicksort(arr, pivot + 1, high);
//     }

void subset_sum_I(int ind, int sum, vector<int> &arr, int n, vector<int> &sumsubset)
{
    if (ind == n)
    {
        sumsubset.push_back(sum);
        return;
    }
    // picking the element
    subset_sum_I(ind + 1, sum + arr[ind], arr, n, sumsubset);
    // not picking the element
    subset_sum_I(ind + 1, sum, arr, n, sumsubset);
}

void subset_sum_II(int ind, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr)
{
    ans.push_back(ds);
    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        subset_sum_II(i + 1, ds, ans, arr);
        ds.pop_back();
    }
}

// combination
// class Solution
// {
// private:
//     void findcombination(int ind, int target, vector<int> &arr,
//                          vector<vector<int>> &ans, vector<int> &ds)
//     {
//         if (ind == arr.size())
//         {
//             if (target == 0)
//             {
//                 ans.push_back(ds);
//             }
//             return;
//         }
//         // pick the element
//         if (arr[ind] <= target)
//         {
//             ds.push_back(arr[ind]);
//             findcombination(ind, target - arr[ind], arr, ans, ds);
//             ds.pop_back();
//         }
//         findcombination(ind + 1, target, arr, ans, ds);
//     }
// public:
//     vector<vector<int>> combinationSum(vector<int> &candidates, int target)
//     {
//         vector<vector<int>> ans;
//         vector<int> ds;
//         findcombination(0, target, candidates, ans, ds);
//         return ans;
//     }
// };



int main()
{

    // fn(5, 5);
    // cout << sumofn(5) << endl;
    // int arr1[] = {1, 2, 3, 4, 5};
    // int n = sizeof(arr1) / sizeof(arr1[0]);

    // // 1.
    // reversearray(arr1, 0, n - 1);
    // reversearray(arr1, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr1[i] << " ";
    // }
    // cout << endl;

    // // 2.
    // string s = "madam";
    // if(stringpali(s,0)){
    //     cout << "palindrome" << endl;
    // }
    // else{
    //     cout << "not palindrome" << endl;
    // }

    // // 3.
    // cout<< fibonacci(4)<<endl;

    // // 4.
    // vector<int> arr = {3,1,2};
    // vector<int> ans = {};
    // print_subsequence(0, arr,ans);

    // // 5.
    // vector<int> arr = {1, 2, 1};
    // vector<int> ans = {};
    // int sum = 0;
    // int sumK = 2;
    // bool found = false;
    // sum_isK_subsequence(0, arr, ans, sum, sumK, found);

    // // 6.
    // vector<int> arr = {1, 2, 1, 5, 4, 3, 7, 4};
    // int n = arr.size();
    // mergesort(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // //  6.
    // vector<int> arr = {1, 2, 1, 5, 4, 3, 7, 4};
    // int n = arr.size();
    // quicksort(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // // 7. combination sum

    // // 8. subset sum I
    // vector<int> arr = {3,1,2};
    // int n = arr.size();
    // int sum = 0;
    // vector<int> sumsubset;
    // subset_sum_I(0, sum, arr, n, sumsubset);
    // sort(sumsubset.begin(),sumsubset.end());
    // for (int i = 0; i < sumsubset.size(); i++)
    // {
    //     cout << sumsubset[i] << " ";
    // }
    // cout << endl;

    // 9. subset sum II
    // vector<int> arr = {3, 1, 2,2,4};
    // sort(arr.begin(), arr.end());
    // int n = arr.size();
    // vector<int> ds;
    // vector<vector<int>> ans;
    // subset_sum_II(0, ds, ans, arr);
    // for (const auto &subset : ans)
    // {
    //     cout << "[";
    //     for (int i = 0; i < subset.size(); i++)
    //     {
    //         cout << subset[i];
    //         if (i != subset.size() - 1)
    //             cout << ", ";
    //     }
    //     cout << "]\n";
    // }

    // // 10. 


    return 0;
}