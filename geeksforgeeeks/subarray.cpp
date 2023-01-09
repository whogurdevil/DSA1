/* link for problem:
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&category[]=Data%20Structures&sortBy=submissions */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        
        vector<int> result (1);
        result[0] = -1;
        if(s == 0){
            return result;
        }
        

    
    int left = 0, right = 0;

    
    int sum = 0;

    // iterate until right pointer is less than size of the array
    while (right < n)
    {
        
        sum += arr[right];

        // if sum is greater than s, it remove elements from the left til sum is smaller than S
        while (sum > s)
        {
            sum -= arr[left];
            left++;
        }

        // if sum is equal to s, return the subarray as result
        if (sum == s)
            return {left + 1, right + 1};

        // move the right pointer to the next element
        right++;
    }

    // for no subarray was found
    return result;
    }
    
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends