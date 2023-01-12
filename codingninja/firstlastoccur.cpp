#include <bits/stdc++.h> 
int firstoccur(vector<int>& arr, int n, int k){
    int start=0, end = n-1, mid = start + (end-start)/2, res = -1;
    while(start <= end){
        if(arr[mid] == k){
            res = mid;
            end = mid -1;
        }
        else if(arr[mid] > k){
            end = mid -1;
        }
        else if(arr[mid] < k){
            start = mid + 1;
        }
        mid = start +(end -start)/2;
    }
    return res;
}

int lastoccur(vector<int>& arr, int n, int k){
    int start=0, end = n-1, mid = start + (end-start)/2, res = -1;
    while(start <= end){
        if(arr[mid] == k){
            res = mid;
            start = mid + 1;
        }
        else if(arr[mid] > k){
            end = mid -1;
        }
        else if(arr[mid] < k){
            start = mid + 1;
        }
        mid = start +(end -start)/2;
    }
    return res;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    
    pair<int,int> res;
    res.first = firstoccur(arr, n, k);
    res.second = lastoccur(arr, n, k);
    return res;
}