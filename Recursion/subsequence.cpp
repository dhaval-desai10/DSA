// #include<iostream>
// #include<vector>
// using namespace std;
// void solve(string str,string output,int index,vector<string>&ans)
// {
//     // base condition
//     if(index==str.size())
//     {
//         ans.push_back(output);
//         return;
//     }
//     // exclude
//     solve(str,output,index+1,ans);
//     // include
//     output.push_back(str[index]);
//     solve(str,output,index+1,ans);
// }
// int main()
// {
//     string str="abc";
//     string output="";
//     vector<string> ans;
//     solve(str,output,0,ans);
//     for(auto i:ans)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//  return 0;
// }
// Output: c b bc a ac ab abc






// //  subsequence solve using bits manipulation. 
//  #include<iostream>
//  #include<vector>
//  using namespace std;
//  class solution {
//      public:
//      vector<vector<int>> subsets(vector<int>& nums) {
//          vector<vector<int>> ans;
//          int n=nums.size();
//          for(int i=0;i<(1<<n);i++)
//          {
//              vector<int> output;
//              for(int j=0;j<n;j++)
//              {
//                  if(i&(1<<j))
//                  {
//                      output.push_back(nums[j]);
//                  }
//              }
//              ans.push_back(output);
//          }
//          return ans;
//      }
//  };
//  int main()
//  {
//      // print using vector.
//      vector<int> nums={1,2,3};
//      solution s;
//      vector<vector<int>> ans=s.subsets(nums);
//      for(auto i:ans)
//      {
//          for(auto j:i)
//          {
//              cout<<j<<" ";
//          }

//          cout<<endl;
//      }
// }







