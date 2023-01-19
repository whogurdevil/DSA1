#include <bits/stdc++.h> 
long long int sumOrProduct(long long int n, long long int q)
{
	long long int sum = 0;
    long long int product = 1;
    if(q == 1){
        for(long long int i = 1; i<=n; i++){
            sum += i;
        }
        return sum;
    }
    else if(q == 2){
        for(long long int i = 2; i<=n; i++){
            product=(product*i)%1000000007;
        }
        return product;
    }
    return 0;
}