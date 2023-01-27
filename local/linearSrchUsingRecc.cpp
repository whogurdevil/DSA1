#include <bits/stdc++.h>
using namespace std;

bool searcharr(int arr[], int size, int target){
    if(size == 0){
        return false;
    }
    if(arr[0] == target){
        return true;
    }
    return searcharr(arr + 1, size - 1, target);
}

int main(){

    int arr1[6]= {1,2,3,4,7,10};
    int arr2[6] = {1,2,5,6,4,2};
    int arr3[6] = {1,2,5,6,7,0};

    cout << "7 in arr1 is : " << searcharr(arr1, 6, 7) << endl;
    cout << "2 in arr1 is : " << searcharr(arr2, 6, 18) << endl;
    cout << "0 in arr1 is : " << searcharr(arr3, 6, 0) << endl;


return 0;
}