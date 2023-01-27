#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size){
    if (size == 0 || size == 1)
    {
        return true;        
    }
    if (arr[0] > arr[1]){
        return false;
    }
    else
    {
        return isSorted(arr+1, --size);
    }
}


int main(){
    int arr1[6]= {1,2,3,4,7,10};
    int arr2[6] = {1,2,5,6,4,2};
    int arr3[6] = {1,2,5,6,7,0};


    cout << isSorted(arr1, 6) << endl;
    cout << isSorted(arr2, 6) << endl;
    cout << isSorted(arr3, 6) << endl;


return 0;
}