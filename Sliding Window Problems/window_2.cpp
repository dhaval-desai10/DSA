#include <bits/stdc++.h>
using namespace std;

// // 1.
void longest_substring_with_at_most_k_distinct_char(string s, int k)
{
    int n = s.length();
    int maxilen = 0;
    unordered_map<char, int> freq;
    // for (int i = 0; i < n; i++)
    // {
    //     freq.clear();
    //     for (int j = i; j < n; j++)
    //     {
    //         freq[s[j]]++;
    //         if (freq.size() <= 2)
    //         {
    //             maxilen = max(maxilen, j - i + 1);
    //         }
    //         else
    //             break;
    //     }
    // }
    

    int l = 0;
    int r = 0;
    while (r < n)
    {
        freq[s[r]]++;

        if (freq.size() > 2)
        {
            freq[s[l]]--;
            if (freq[s[l]] == 0)
            {
                freq.erase(s[l]);
            }
            l++;
        }
        else if (freq.size() <= k)
        {
            maxilen = max(maxilen, r - l + 1);
        }
        r++;
    }
    cout << "maxi length : " << maxilen << endl;
}

// // 2.
// // leetcode 992 subarray with k diffrent integer



int subarraysWithKDistinct(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    // // brute-force
    // for (int i = 0; i < n; i++)
    // {
    //     map<int, int> freq;
    //     for (int j = i; j < n; j++)
    //     {
    //         freq[nums[j]]++;
    //         if (freq.size() == k)
    //         {
    //             count++;
    //         }
    //         else if (freq.size() > k)
    //         {
    //             break;
    //         }
    //     }
    // }

    // two-pointer approach
    int l = 0, r = 0;
    map<int, int> freq;
    while (r < n)
    {
        freq[nums[r]]++;
        while (freq.size() <= k)
        {
            freq[nums[l]]--;
            if (freq[nums[l]] == 0)
            {
                freq.erase(nums[l]);
            }
            l--;
        }
        count = count + (r - l + 1);
        r++;
    }

    return count;
}
int finalcount(vector<int> &nums, int k){
    return subarraysWithKDistinct(nums, k) - subarraysWithKDistinct(nums, k - 1);
}



int main()
{
    // // 1.
    // string s = "aaabbccd";
    // int k = 2;
    // longest_substring_with_at_most_k_distinct_char(s, k);

    // // 2.
    vector<int> nums = {1, 2, 1, 3, 4};
    int k = 3;
    cout<< "final count : "<< finalcount(nums, k)<<endl;

    return 0;
}