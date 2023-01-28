#include <bits/stdc++.h>
using namespace std;

void sortarr(int arr[], int size){
    //base case
    if(size == 0 || size == 1){
        return;
    }
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    sortarr(arr,--size);

}

int main(){
    int size  = 7;
    int arr[size] = {7,6,5,4,3,2,1};

    sortarr(arr, size);

    for(int i = 0; i< size; i++){
        cout << arr[i] << " ";
    }
return 0;
}