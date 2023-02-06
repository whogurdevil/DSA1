class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;

        int fstp = 0;
        int scndp = n;
        while(fstp < n+1 && scndp < 2*n){
            ans.push_back(nums[fstp++]);
            ans.push_back(nums[scndp++]);
        }

        return ans;
    }
};