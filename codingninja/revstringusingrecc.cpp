#include <bits/stdc++.h>
using namespace std;

void rev(int i, string& str){
	if(i >= (str.length()-1-i) ){
		return;
	}
	swap(str[i], str[str.length()-1-i]);
	
	rev(++i, str);
}

string reverseString(string str)
{
	rev(0, str);

	return str;
}