#include <bits/stdc++.h> 
bool ispossible(vector<int> time,long long int n, long long int m, long long int mid){
    long long int timesum = 0;
    long long int chptr = 1;
    
    for(int i = 0; i<m;i++){
        if(timesum + time[i] <=mid){
            timesum += time[i]; 
        }
        else{
            chptr++;
            if(chptr > n|| mid < time[i]){
                return false;
            }
            timesum = time[i];
            
            }
        if(chptr > n){
                return false;
        }
    }
    return true;
}


long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{    
    long long int sum = 0;
    
    for(int i = 0; i<m;i++){
        sum += time[i];
    }
    
    
    long long int s = 0;
    long long int e = sum;
    long long int mid = s + (e-s)/2;
    long long int ans = -1;
    
    while(s <= e){
        if(ispossible(time, n, m, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}