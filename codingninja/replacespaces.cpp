#include <bits/stdc++.h> 
char tolower(char str){
    if(str >= 'A' && str <= 'Z'){
        return (str - 'A' + 'a');
    }
    else{
        return str;
    }
    return str;
}

bool checkPalindrome(string s)
{
    int st = 0, e = s.size() - 1;
    while( st <= e){
        if(iswalnum(s[st]) == false){
            st++;
            continue;
        }
        if(iswalnum(s[e]) == false){
            e--;
            continue;
        }
        
        if(tolower(s[st]) != tolower(s[e])){
            return false;
            break;
        }
        st++;
        e--;
    }
    return true;
    
}