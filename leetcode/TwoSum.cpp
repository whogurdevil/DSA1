class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result (2);
        
        for(int i = 0; i<nums.size(); i++){
            int temp = nums[i];
            for(int j = 0; j<nums.size(); j++){
                if(j == i){
                    continue;
                }
                else if(temp + nums[j] == target){
                    result[0] = i;
                    result[1] = j;
                    break;
                }
                
            }
        }
        return result;
    }
    
};