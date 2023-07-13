#include <bits/stdc++.h> 
#include <stack>
int findMinimumCost(string str) {
  if(str.length() & 1){
    return -1;
  }

  stack<char> st;

  for(int i = 0; i < str.length(); i++){
    if(str[i] == '{'){
      st.push(str[i]);
    }
    else{
      if(!st.empty() && st.top() == '{'){
        st.pop();
      }
      else{
        st.push(str[i]);
      }
    }
  }

  int opencount = 0, closecount = 0;

  while(!st.empty()) {
    if(st.top() == '{'){
      opencount++;
    }
    else{
      closecount++;
    }

    st.pop();
  }

  int ans = (opencount+1)/2 + (closecount+1)/2;
  return ans;

}