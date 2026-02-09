#include <bits/stdc++.h>
using namespace std;

// // 1.removing duplicate elements

void remove_duplicate(vector<int> &arr)
{
    // // 1.
    // set<int> st;
    // for(int i = 0;i<arr.size();i++){
    //     st.insert(arr[i]);
    // }
    // for(auto& it : st){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    // // optimized
    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    cout << "length : " << i + 1 << endl;
}

// // 2.left rotation of array by k places

void left_rotate_byK(vector<int> &arr, int d)
{

    int n = arr.size();
    d = d % n;
    vector<int> temp;
    // for(int i = 0;i<d;i++){
    //     temp.push_back(arr[i]);
    // }

    // for(int i = d;i<n;i++){
    //     arr[i-d] = arr[i];
    // }
    // int j = 0;
    // for(int i = n-d;i<n;i++){
    // //arr[i] = temp[i - (n-d)];
    // arr[i] = temp[j];
    // j++;
    // }

    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void right_rotation_byK(vector<int> &arr, int d)
{
    int n = arr.size();
    // reverse(arr.begin(),arr.begin() + n - d);
    // reverse(arr.begin() + n - d,arr.end());
    // reverse(arr.begin(),arr.end());

    vector<int> temp;
    for (int i = n - d; i < n; i++)
    {
        temp.push_back(arr[i]);
    }
    for (int i = n - 1; i >= d; i--)
    {
        arr[i] = arr[i - d];
    }

    for (int i = 0; i < d; i++)
    {
        arr[i] = temp[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void move_all_zero_toright(vector<int> &arr)
{
    int j = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void union_of_array(vector<int> &arr1, vector<int> &arr2)
{
    // set<int> st;
    // for (int i = 0; i < arr1.size(); i++)
    // {
    //     st.insert(arr1[i]);
    // }
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     st.insert(arr2[i]);
    // }

    // for (auto it : st)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    vector<int> a = arr1, b = arr2;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> result;
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        int val;
        if (a[i] < b[j])
        {
            val = a[i];
            i++;
        }
        else if (b[j] < a[i])
        {
            val = b[j];
            j++;
        }
        else
        {
            val = a[i];
            i++;
            j++;
        }
        if (result.empty() || result.back() != val)
        {
            result.push_back(val);
        }
    }
    while (i < n1)
    {
        if (result.empty() || result.back() != a[i])
        {
            result.push_back(a[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (result.empty() || result.back() != b[j])
        {
            result.push_back(b[j]);
        }
        j++;
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

void intersection_a(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> ans;
    vector<int> visit(arr2.size(), 0);

    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if (arr1[i] == arr2[j] && visit[j] == 0)
            {
                ans.push_back(arr1[i]);
                visit[j] = 1;
                break;
            }
        }
    }

    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void missing_number(vector<int> arr)
{
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        bool flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "ans " << i << endl;
    }

    // // using sum method
    int sum = (n + 1) * n / 2;
    int arrsum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        arrsum += arr[i];
    }
    cout << "ans using sum : " << sum - arrsum << endl;

    // // using XOR bit manipulation

    int xor1 = 0;
    int xor2 = 0;
    for (int i = 1; i <= n; i++)
    {
        xor1 ^= i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        xor2 ^= arr[i];
    }
    cout << "using xor ans is " << (xor1 ^ xor2) << endl;
}

void consecutive_1(vector<int> &arr)
{
    int n = arr.size();
    int count_1 = 0;
    int maxcount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count_1++;
            maxcount = max(maxcount, count_1);
        }
        else
        {
            count_1 = 0;
        }
    }
    cout << "maxcount : " << maxcount << endl;
}

void findi_single_appears(vector<int> &arr)
{
    int xorr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xorr = xorr ^ arr[i];
    }
    cout << "appearing once in array : " << xorr << endl;
}

void print_all_subarray(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            vector<int> temp;
            for (int k = i; k <= j; k++)
            {
                temp.push_back(arr[k]);
            }
            ans.push_back(temp);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void subarray_with_sumK(vector<int> &arr, int s)
{
    int n = arr.size();
    vector<vector<int>> ans;
    int maxlen = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         int sum = 0;
    //         for (int k = i; k <= j; k++)
    //         {
    //             sum += arr[k];
    //         }
    //         if (sum == s)
    //         {
    //             maxlen = max(maxlen, j - i + 1);
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += arr[j];
    //         if (sum == s)
    //         {
    //             maxlen = max(maxlen, j - i + 1);
    //         }
    //     }
    // }

    // cout << "maxilen : " << maxlen << endl;

    // // better approach
    // int left = 0;
    // int right = 0;

    // long long sum = arr[0];

    // while (right < n)
    // {
    //     while (sum > s && left <= right)
    //     {
    //         sum -= arr[left];
    //         left++;
    //     }
    //     if (sum == s)
    //     {
    //         maxlen = max(maxlen, right - left + 1);
    //     }
    //     right++;
    //     if (right < n)
    //         sum += arr[right];
    // }
    // cout << "maxilen : " << maxlen << endl;

    map<long long, int> presum;
    long long sum = 0;
    int maxilen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == s)
        {
            maxilen = max(maxilen, i + 1);
        }
        long long rem = sum - s;
        if (presum.find(rem) != presum.end())
        {
            int len = i - presum[rem];
            maxilen = max(maxilen, len);
        }
        // // only for the positive elements in the array not for zero also

        // // for zaro add condition do not update the prevsum
        if (presum.find(sum) == presum.end())
        {
            presum[sum] = i;
        }
        presum[sum] = i;
    }
    cout << "maxilength : " << maxilen << endl;
}

int main()
{
    vector<int> arr1 = {1, 1, 0, 0, 1, 1};
    vector<int> arr2 = {1, 2, 0, 1, 3, 4, 7};
    // vector<int> arr = {1, 6, 2, 2, 2, 3, 3};
    vector<int> arr = {2, 0, 0, 0, 3};

    // // 1.
    // remove_duplicate(arr2);

    // // 2.
    // left_rotate_byK(arr2, 3);

    // // 3.
    // right_rotation_byK(arr2, 3);

    // // 4. move zeros
    // move_all_zero_toright(arr);

    // // 5. union of array
    // union_of_array(arr1, arr2);

    // // 4.
    // intersection_a(arr1, arr2);

    // // 5.
    // missing_number(arr);

    // // 6.
    // consecutive_1(arr1);

    // // 9.
    // findi_single_appears(arr);

    // // 7.
    // print_all_subarray(arr);

    // // 8.
    subarray_with_sumK(arr, 3);

    return 0;
}
