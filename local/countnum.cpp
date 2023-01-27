#include <bits/stdc++.h>
using namespace std;

void countnum(int n, string arr[]){
    
    //base case
    if (n == 0)
    {
        return;
    }

    int digit = n%10;
    n /= 10;

    countnum(n, arr);

    cout << arr[digit] << endl;
}

int main(){

    string arr[10] = {"zero", "one", "two", "three", "four","five", "six", "seven", "eight", "nine"};

    cout << "Enter number to print each numeral: " ;
    int count;
    cin >> count;

    countnum(count, arr);

return 0;
}