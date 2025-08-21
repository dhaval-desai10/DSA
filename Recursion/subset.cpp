#include<iostream>
#include<vector>
using namespace std;
class solution {
    private:
    void solve(vector<int>nums,vector<int> output,int index,
    vector<vector<int>>& ans)
    {
        // base condition
        if(index==nums.size())
        {
            ans.push_back(output);
            return;
        }
        // exclude
        solve(nums,output,index+1,ans);
        // include
        output.push_back(nums[index]);
        solve(nums,output,index+1,ans);
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums,output,0,ans);
        return ans;
    }

};
int main()
{
    // print using vector.
    vector<int> nums={1,2,3};
    solution s;
    vector<vector<int>> ans=s.subsets(nums);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
   
 return 0;
}