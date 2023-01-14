bool ispossible(vector<int> &boards, int k, int mid){
    int pntrcount = 1;
    int boardno = 0;
    
    for(int i = 0; i<boards.size(); i++){
        if(boardno + boards[i] <= mid){
            boardno += boards[i];
        }
        else{
            pntrcount++;
            if(pntrcount > k || boards[i] > mid){
                return false;
            }
            boardno = boards[i];
            }
        if(boards[i] > mid){
            return false;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int sum = 0;
    for(int i = 0; i < boards.size(); i++){
        
        sum += boards[i];
    }
    
    int s = 0;
    int e = sum;
    
    int mid = s + (e-s)/2;
    
    int ans = -1;
    
    while(s <= e){
        if(ispossible(boards, k, mid)){
            ans = mid;
            e = mid - 1 ;
        }
        else{
            s = mid + 1 ;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}