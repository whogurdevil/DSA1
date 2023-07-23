//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
#include <stack>
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
       // add code here.
       queue<int> ans;
       if(q.empty()) {
           return ans;
       }
       stack<int> s;
       
       while(!q.empty()) {
           
           s.push(q.front());
           q.pop();
           
       }
       
       while(!s.empty()) {
           
           ans.push(s.top());
           s.pop();
       }
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends