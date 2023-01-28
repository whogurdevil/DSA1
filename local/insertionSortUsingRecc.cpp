#include <bits/stdc++.h>
using namespace std;

// not completed

void sortarr(int arr[], int size, int ind){
    if(size == 0 || size == 1 ){
        return;
    }


}

int main(){
    int size  = 7;
    int arr[size] = {7,6,5,4,3,2,1};

    sortarr(arr, size, 0);

    for(int i = 0; i< size; i++){
        cout << arr[i] << " ";
    }
return 0;
}