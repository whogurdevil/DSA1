class Solution {
private:

    double solve(double x, int n){
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }

        if(n < 0){
            double ans=solve(x, n/2);
            if(n&1){
            ans = ans*ans*(1/x);
            }
            else{
                ans = ans*ans;
            }
            return ans;
        }

        double ans = solve(x, n/2);
        if(n&1){
            ans = ans*ans*x;
        }
        else{
            ans = ans*ans;
        }
        
        
        
        return ans;
        
    }

public:
    double myPow(double x, int n) {
        return(solve(x,n));
    }
};