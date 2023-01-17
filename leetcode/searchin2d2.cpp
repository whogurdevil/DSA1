class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rindex = 0;
        int cindex = col -1;

        while(rindex < row && cindex >= 0 ){
            int element = matrix[rindex][cindex];

            if(target == element){
                return true;
            }
            if(target < element){
                cindex--;
            }
            if(target > element){
                rindex++;
            }
        }
        return false;

    }
};
