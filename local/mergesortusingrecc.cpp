#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e){

    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;
    
    int *first = new int[len1];
    int *second = new int[len2];

    int arrayind = s;
    
    for(int i = 0; i < len1; i++){
        first[i] = arr[arrayind++];
    }

    arrayind = mid + 1;

    for(int i = 0; i < len2; i++){
        second[i] = arr[arrayind++];
    }


    int ind1 = 0;//for first arr
    int ind2 = 0;//for second arr
    arrayind = s; // for orignal arr

    while(ind1 < len1 && ind2 < len2 ){
        if(first[ind1] < second[ind2])
            arr[arrayind++] = first[ind1++];

        else
            arr[arrayind++] = second[ind2++];
    }

    while(ind1 < len1){
        arr[arrayind++] = first[ind1++];
    }

    while(ind2 < len2){
        arr[arrayind++] = second[ind2++];
    }


}

void sortarr(int *arr, int s, int e){

    if(s >= e)
    return;

    int mid = s + (e-s)/2;
    //left part
    sortarr(arr, s, mid );

    //right part
    sortarr(arr, mid+1, e);

    //merge a+sorted arrays
    merge(arr, s, e);
}

int main(){
    int size  = 7;
    int arr[size] = {7,6,5,4,3,2,1};

    sortarr(arr,0,size-1);

    for(int i = 0; i< size; i++){
        cout << arr[i] << " ";
    }

    
return 0;
}