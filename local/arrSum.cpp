#include <bits/stdc++.h>
using namespace std;

int arrSum(int arr[], int size){
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }

    return arr[0] + arrSum(arr+1, size-1);
}

int main(){
    int arr1[5] = {1,3,5,2,2};
    int arr2[1] = {2};
    int arr3[3] = {5,34,3};

    cout << "Sum of arr1: " << arrSum(arr1, 5) << endl;
    cout << "Sum of arr2: " << arrSum(arr2, 1) << endl;
    cout << "Sum of arr3: " << arrSum(arr3, 3) << endl;



return 0;
}