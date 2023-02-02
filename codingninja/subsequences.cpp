#include <bits/stdc++.h> 
using namespace std;

void solve(string str, int index, string output, vector<string>& ans){
	if(index >= str.length()){
		if(output.length() > 0){
			ans.push_back(output);
		}
		
		return;
	}

	//exclude
	solve(str, index+1, output, ans);

	//include
	output.push_back(str[index]);
	solve(str, index+1, output, ans);


}

vector<string> subsequences(string str){
	
	vector<string> ans;
	string output= "";
	solve(str,0,output,ans);

	return ans;
	
}
