#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
      char t = s[i];

      if (t == '(' || t == '+' || t == '-' || t == '*' || t == '/') {
        st.push(t);
      }
      else{
          
        if(t == ')'){
          bool isredundent = true;
          while(st.top() != '('){
              char chk = st.top();
              if(chk == '+' || chk == '-' || chk == '*'  || chk == '/'){
                isredundent = false;
              }
              st.pop();
          }
            st.pop();
          if(isredundent == true){
              return true;
          }  
        }
      }
    }

    return false;

}
