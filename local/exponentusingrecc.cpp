#include <bits/stdc++.h>
using namespace std;

int power(int num, int pow){
    if(pow == 0){
        return 1;
    }
    if(pow == 1){
        return num;
    }

    int ans = power(num, pow/2);

    if(pow&1){
        return num * ans * ans;
    }
    else {
        return ans * ans;
    }
}

int main(){
    int num,pow;

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter power: ";
    cin >> pow;

    cout << "Answer is: " << power(num, pow);
return 0;
}