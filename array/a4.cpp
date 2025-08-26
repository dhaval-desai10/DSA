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
    // arr[i] = temp[i - (n-d)];
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



int main()
{
    vector<int> arr1 = {1, 1, 1, 2, 2, 3, 4, 4};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};

    // // 1.
    // remove_duplicate(arr2);

    // // 2.
    // left_rotate_byK(arr2, 3);

    // // 3.
    // right_rotation_byK(arr2, 3);

    // // 4.
    intersection_a(arr1, arr2);

    return 0;
}
