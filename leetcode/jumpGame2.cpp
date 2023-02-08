class Solution {
public:
    int jump(vector<int>& nums) {
        int numjumps = 0, n = nums.size(), curEnd = 0, curFar = 0;

        for(int i = 0; i < n; i++){
            curFar = max(curFar, i+nums[i]);

            if(curEnd == i && i != n-1){
                numjumps++;
                curEnd = curFar;
            }
        }
        return numjumps;
    }
};