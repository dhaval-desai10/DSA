#include <bits/stdc++.h>
using namespace std;

int findcount(vector<int> v, int pages)
{
    int student_count = 1, studnet_have_pages = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (studnet_have_pages + v[i] <= pages)
        {
            studnet_have_pages += v[i];
        }
        else
        {
            student_count++;
            studnet_have_pages = v[i];
        }
    }
    return student_count;
}

// // linear  
// int bookallocate(vector<int> v, int k)
// {
//     int maxi = -1;
//     int sum = 0;
//     for (int i = 0; i < v.size(); i++)
//     {
//         maxi = max(maxi, v[i]);
//         sum += v[i];
//     }
//     int high = sum;
//     int low = maxi;
//     int count_student;
//     for (int pages = low; pages <= high; pages++)
//     {
//         count_student = findcount(v, pages);
//         if (count_student == k)
//         {
//             return pages;
//         }
//     }
//     return -1;
// }

// // binary search
 int bookallocate(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            sum += nums[i];
        }
        int high = sum;
        int low = maxi;
        // int mid;
        int count_student;
        while (low <= high) {
            int mid = (low + high) / 2;
            count_student = (findcount(nums, mid));
             if (count_student > k) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return low;
    }
int main()
{
    vector<int> v = {25, 46, 28, 49, 24};
    int k = 4;
    int ans = bookallocate(v, k); // linear and binaray
    cout << ans << endl;
    return 0;
}