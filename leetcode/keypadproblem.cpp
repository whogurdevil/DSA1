

class Solution {
private: 
    void solve(string digits, int index, string output, vector<string>& ans, string map[]){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] -'0';
        string value = map[number];

        for(int i = 0; i < value.size(); i++){
            output.push_back(value[i]);
            solve(digits,index+1,output,ans,map);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }

        string output = "";
        string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, 0, output, ans, map);

        return ans;
    }
};