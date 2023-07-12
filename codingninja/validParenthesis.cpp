bool isValidParenthesis(string s)
{
    stack<char> st;
    for(int i = 0; i <s.length(); i++){
        char ele = s[i];

        if(ele == '{' || ele == '(' || ele == '[' ){
            st.push(ele);
        }
        else{
          if (!s.empty()) {
                if(ele == ')' && st.top() == '(' ||
                ele == '}' && st.top() == '{' ||
                ele == ']' && st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
          }
          else{
            return false;
          }
        }
    }

    if(st.empty())
        return true;
    else   
        return false;
        }