int maximumFrequency(vector<int> &arr, int n)
{   
        int maxfreq =0;
        int maxn = 0;
        unordered_map<int,int> count;
        
        for(int i = 0; i<arr.size(); i++){
            count[arr[i]]++;
            maxfreq = max(maxfreq, count[arr[i]]);
        }
        for(int i =0; i<arr.size(); i++){
            if(maxfreq == count[arr[i]]){
                maxn = arr[i];
                break;
            }
        }
        
        return maxn;
        
        
    
}