class Solution {
private:

void solve(vector<int> nums, int index, vector<int> output, vector<vector<int>>& ans){
    //base case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, index+1, output, ans);

    // include
    output.push_back(nums[index]);
    solve(nums, index+1, output, ans);

}


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        int index = 0;
        vector<vector<int>> ans;

        solve(nums, index, output, ans);

        return ans;
    }
};