// #include<iostream>
// using namespace std;
// int main()
// {
//     int arr1[]={1,3,4,5};
//     int  arr2[]={2,6,8,9};
//     int arr3[8];
//     int i=0,j=0,k=0;
//     for(int i=0;i<4;i++){
//         arr3[i]=arr1[i];

//     }
//     for(int i=0;i<4;i++)
//     {
//         arr3[i+4]=arr2[i];

//     }
//     for(int i=0;i<8;i++)
//     {
//         for(int j=i+1;j<8;j++)
//         {
//             if(arr3[j]<arr3[i])
//             {
//                 int temp;
//                 temp=arr3[j];
//                 arr3[j]=arr3[i];
//                 arr3[i]=temp;
//             }
//         }
//     }
//     for(int i=0;i<8;i++)
//     {
//         cout<<arr3[i]<<" ";
//     }cout<<endl;
//  return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[10] = {1,3,2,2,5,2,3,7};
//     int n = 8;
//     int count;
//     int maxicount = 0;
//     for(int i = 0;i<n;i++){
//         count = 1;
//         for(int j=i+1;j<n;j++){
//             if(arr[j] == (arr[i] + 1) || arr[j] == (arr[i] -1) || arr[j] == arr[i]) {
//                 count++;
//             }
//             maxicount = max(maxicount,count);
//         }
//     }
//     cout<<"maxicount"<<maxicount<<endl;
//  return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     map<int,char> alpha;
//     for(int i=1;i<=26;i++){
//         alpha[i]='a'+i-1;
//     }
//     // for(auto& it : alpha){
//     //     cout<<it.first<<"-"<<it.second<<endl;
//     // }
//     // cout<<alpha[5]<<endl;

//  return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
{
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int count = 0;
    int j = 0;

    for (int i = 0; i < players.size() && j < trainers.size(); i++)
    {
        // Find a trainer who can train this player
        while (j < trainers.size() && trainers[j] < players[i])
        {
            j++;
        }

        // If we found a suitable trainer
        if (j < trainers.size())
        {
            count++;
            j++; // Move to next trainer
        }
    }

    return count;
}
int main()
{
    vector<int> players = {4, 7, 9};
    vector<int> trainers = {8, 2, 5, 8};
    cout << matchPlayersAndTrainers(players, trainers) << endl;

    return 0;
}