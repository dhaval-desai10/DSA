#include <bits/stdc++.h>
using namespace std;
// // 1. two sum problem

void two_sum(vector<int> &arr, int target)
{
    // int a = -1, b = -1;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = i + 1; j < arr.size(); j++)
    //     {
    //         if (arr[i] + arr[j] == target)
    //         {
    //             a = arr[i];
    //             b = arr[j];
    //         }
    //     }
    // }
    // cout << "yes its possible : " << a << " + " << b << endl;

    // // hashing

    // unordered_map<int, int> mp;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     int complement = target - arr[i];
    //     if (mp.find(complement) != mp.end())
    //     {
    //         cout << "yes its possible : " << arr[i] << " + " << complement << endl;
    //         return;
    //     }
    //     mp[arr[i]] = i;
    // }
    // cout << "No such pair found" << endl;

    // // optimal solution of above by not using extra sapce

    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        if (arr[left] + arr[right] == target)
        {
            cout << "yes its possible : " << arr[left] << " + " << arr[right] << endl;
            return;
        }
        else if (arr[left] + arr[right] < target)
        {
            left++;
        }
        else
            right--;
    }
}

// // 2 . sort array having 0 , 1 , 2 only
void sort_arr_0_1_2(vector<int> &arr)
{

    // // brute force is sort function gives nlogn

    // // better (as contain only 0 1 2) do in one iteration

    // int count0 = 0, count1 = 0, count2 = 0;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if (arr[i] == 0)
    //         count0++;
    //     else if (arr[i] == 1)
    //         count1++;
    //     else
    //         count2++;
    // }
    // for (int i = 0; i < count0; i++)
    // {
    //     arr[i] = 0;
    // }
    // for (int i = count0; i < (count0 + count1); i++)
    // {
    //     arr[i] = 1;
    // }
    // for (int i = count0 + count1; i < arr.size(); i++)
    // {
    //     arr[i] = 2;
    // }

    // most optimal : Dutch National Flag Algorithm
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// // 3. majority element count must-> (count > n/2)
void majority_element(vector<int> &arr)
{

    // // brute force using two for loops
    // // better by using hashing

    // // optimal by using Moore's Voting algorithm

    int count = 0;
    int ele;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            ele = arr[i];
        }
        else if (arr[i] == ele)
        {
            count++;
        }
        else
            count--;
    }
    cout << "majority element is : " << ele << endl;
}

void maximum_subarray_sum(vector<int> &arr)
{
    // // brute force(use three loop) and better(using two loop)  by try out all subarray maxi sum
    // int maxisum = 0;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < arr.size(); j++)
    //     {
    //         sum += arr[j];
    //         maxisum = max(maxisum, sum);
    //     }
    // }
    // cout << "maxisum of subarray is : " << maxisum << endl;

    // // most optimal solution is Kadan's algorithm

    int maxisum = INT_MIN;
    int sum = 0;
    int ansstart, ansend;

    for (int i = 0; i < arr.size(); i++)
    {
        // // for priting subarray we start when sum is 0 end when sum > maxi
        if (sum == 0)
        {
            ansstart = i;
        }

        sum += arr[i];
        if (sum > maxisum)
        {
            maxisum = sum;
            ansend = i;
        }
        else if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << "maxisum of subarray is : " << maxisum << endl;
    for (int i = ansstart; i <= ansend; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// // rearranging element by sign

void rearranigin_sign(vector<int> &arr)
{
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
        else
            pos.push_back(arr[i]);
    }
    // for (int i = 0; i < arr.size() / 2; i++)
    // {
    //     arr[2 * i] = pos[i];
    //     arr[(2 * i) + 1] = neg[i];
    // }
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // // if not having same pos and neg

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[(2 * i) + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[(2 * i) + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// // next permutation

void next_Permutation(vector<int> &arr)
{
    // // brute force by genereating all permutaion and then do linear search and find next permutaiton
    // // better approch is to use the next_permutaion inbuild STL of c++

    // // optimal solution is this

    // first finding the peak element were there is break point
    int ind = -1;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    // find element which is greater than arr[ind] but smallest one
    for (int i = arr.size() - 1; i > ind; i--)
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }
    reverse(arr.begin() + ind + 1, arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// // leaders elements in array , array element-> on right side no any element is greater than that element
/// last element is always leader because no any element on its right

void longest_consecutive_sequence(vector<int> &arr)
{
    // // brute force
    int maxi_len = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int curr = arr[i];
        int count = 1;
        // Check for next consecutive elements
        while (find(arr.begin(), arr.end(), curr + 1) != arr.end())
        {
            curr++;
            count++;
        }
        maxi_len = max(maxi_len, count);
    }
    cout << "maxi consecutive length : " << maxi_len << endl;

    // // most optimal solution
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        st.insert(arr[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x += 1;
                count += 1;
            }
            longest = max(longest, count);
        }
    }
    cout << "maxi consecutive length : " << longest << endl;
}

// // set matrix zero

void markRow(int i, vector<vector<int>> &matrix)
{
    int n = matrix[0].size();
    for (int j = 0; j < n; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}
void markCol(int j, vector<vector<int>> &matrix)
{
    int m = matrix.size();
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void set_matrix_zero(vector<vector<int>> &matrix)
{

    int m = matrix.size();
    int n = matrix[0].size();

    // //  brute force

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (matrix[i][j] == 0)
    //         {
    //             markRow(i, matrix);
    //             markCol(j, matrix);
    //         }
    //     }
    // }
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (matrix[i][j] == -1)
    //             matrix[i][j] = 0;
    //     }
    // }

    // // more better brute force

    // int markrow[m] = {0};
    // int markcol[n] = {0};
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (matrix[i][j] == 0)
    //         {
    //             markrow[i] = 1;
    //             markcol[j] = 1;
    //         }
    //     }
    // }
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (markcol[j] || markrow[i])
    //         {
    //             matrix[i][j] = 0;
    //         }
    //     }
    // }

    // // most optimal solution

    // Get dimensions of matrix

    // Flag to track if first row should be zeroed
    bool firstRowZero = false;
    // Flag to track if first column should be zeroed
    bool firstColZero = false;

    // Check if first row has any zero
    for (int j = 0; j < n; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }

    // Check if first column has any zero
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }

    // Mark rows and columns in first row/column
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set matrix cells to zero based on markers
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Handle first row
    if (firstRowZero)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }

    // Handle first column
    if (firstColZero)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }

    // // print

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// // count subarray with sum is k
void count_subarrays_sumK(vector<int> &arr, int k)
{
    int count = 0;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < arr.size(); j++)
    //     {
    //         sum += arr[j];
    //         if (sum > k)
    //             break;
    //         if (sum == k)
    //         {
    //             count++;
    //         }
    //     }
    // }

    // // most optimal solution is using prefix sum and doing reverse engineering

    map<int, int> mpp;
    mpp[0] = 1;
    int presum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        presum += arr[i];
        int rem = presum - k;
        count += mpp[rem];
        mpp[presum]++;
    }

    cout << "Numer of subarray having sum " << k << " is : " << count << endl;
}

int main()
{
    // vector<int> arr = {2, 0, 0, 1, 2, 1, 1, 0};
    // // 1.
    // vector<int> arr = {2, 4, 5, 7, 8, 3};
    // int target = 11;
    // two_sum(arr, target);

    // // 2.
    // sort_arr_0_1_2(arr);

    // // 3.
    // vector<int> arr = {2, 0, 2, 1, 2, 1, 1, 2, 2, 2, 1};
    // majority_element(arr);

    // // 4.
    // vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    // maximum_subarray_sum(arr);

    // // 5.
    // vector<int> arr = {-3, -1, -2, -5, 2, -4, -5, 1};
    // rearranigin_sign(arr);

    // // 6.
    // vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    // // vector<int> arr = {4, 3, 2};
    // next_Permutation(arr);

    // // 7.
    // vector<int> arr = {10, 22, 12, 3, 0, 6};
    // // vector<int> arr = {1,2,4};
    // leaders_in_arr(arr);

    // // 8.
    // vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 5, 1};
    // longest_consecutive_sequence(arr);

    // // 9.
    // vector<vector<int>> matrix = {{0, 1, 2, 0},
    //                               {3, 4, 5, 2},
    //                               {1, 3, 1, 5}};
    // set_matrix_zero(matrix);

    // // 10.
    vector<int> arr = {2, 2, 3, 4, 5};
    count_subarrays_sumK(arr, 7);

    return 0;
}   