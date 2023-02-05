//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isSafe(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>>& visit){
        if((x >= 0 && x < n) && (y >= 0 && y < n) && (visit[x][y] == 0) && (m[x][y] == 1)){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>>& visit, string path, vector<string>& ans){
        //base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visit[x][y] = 1;
        
        //down
        int newx = x+1;
        int newy = y;
        if(isSafe(newx, newy, m, n, visit)){
            path.push_back('D');
            solve(newx, newy, m, n, visit, path, ans);
            path.pop_back();
        }
        
        //left
        newx = x;
        newy = y-1;
        if(isSafe(newx, newy, m, n, visit)){
            path.push_back('L');
            solve(newx, newy, m, n, visit, path, ans);
            path.pop_back();
        }
        
        //up
        newx = x-1;
        newy = y;
        if(isSafe(newx, newy, m, n, visit)){
            path.push_back('U');
            solve(newx, newy, m, n, visit, path, ans);
            path.pop_back();
        }
        
        //right
        newx = x;
        newy = y+1;
        if(isSafe(newx, newy, m, n, visit)){
            path.push_back('R');
            solve(newx, newy, m, n, visit, path, ans);
            path.pop_back();
        }
        
        visit[x][y] = 0;
        
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0] == 0){
            return ans;
        }
        
        
        vector<vector<int>> visit = m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visit[i][j] = 0;
            }
        }
        
        int srcx = 0;
        int srcy = 0;
        string path = "";
        
        solve(srcx, srcy, m, n, visit, path, ans);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};


    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends