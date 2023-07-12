#include <bits/stdc++.h> 

void solve(stack<int>&inputStack, int count, int size){
   //base case
   if(count == size/2){
      inputStack.pop();
      return;   }

   // save top element;
   int save = inputStack.top();
   inputStack.pop();
   
   //recursive
   solve(inputStack, ++count, size);

   //push saveed element
   inputStack.push(save);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   int count = 0;
   solve(inputStack, count, N);
   
}