#include <bits/stdc++.h> 
void insertSorted(stack<int>& st, int x) {
	if(st.empty() || st.top() <= x) {
		st.push(x);
		return;
	}

	int num = st.top();
	st.pop();

	insertSorted(st, x);

	st.push(num);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}

	int num = stack.top();
	stack.pop();

	sortStack(stack);

	insertSorted(stack, num);
}