class Solution {
private:
int gcd(long a, long b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a != b){
        if(a > b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = gcd(nums[0], nums[nums.size()-1]);
        return ans;
    }
};