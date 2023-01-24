#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
#include <vector>
using namespace std;

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int s = 0;
    int e = m*n - 1;

    int mid = s + (e-s)/2;

    while(s <= e){
        if(mat[mid/n][mid%n] == target){
            return true;
        }
        else if(mat[mid/n][mid%n] < target){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return false;
}