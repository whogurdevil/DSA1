#include <bits/stdc++.h> 
void solve(stack<int>& st, int x) {
    if(st.empty()){
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    solve(st, x);

    st.push(temp);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;

}
