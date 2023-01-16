
class Solution {
    private:
    bool isvalid(char str){
    if((str >= 'A' && str <= 'z' )||(str >= 'a' && str <= 'z') || (str >= '0' && str <= '9')){
        return true;
    }
    else{
    return false;
    }
    return false;
}
char tolowercase(char str){
    if(str >= 'a' && str <= 'z' || str >= '0' && str <= '9'){
        return str;
    }
    return (str - 'A' + 'a');
}

bool palindrome(string str){
    int s = 0, e = str.length() -1;

    while(s <= e){
        if(str[s] != str[e]){
            return false;
        }

        s++;
        e--;
    }
    return true;
}
public:
    bool isPalindrome(string s) {
        string temp = "";

        for(int i=0; i<s.length(); i++){
            if(isvalid(s[i])){
                temp.push_back(s[i]);
            }
        }

        for(int j = 0; j < temp.length(); j++){
            temp[j] = tolowercase(temp[j]);
        }

       return (palindrome(temp));
    }
};