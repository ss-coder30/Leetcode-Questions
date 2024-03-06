class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = x;
        
        if(x == 1){
            return 1;
        }
        
        if(x == 0) return 0;
        
        while(high - low > 1){
            long long mid = (high + low)/2;
            if(mid * mid > x){
                high = mid-1;
            }
            else{
                low = mid;
            }
        }
        
        if(high * high <= x) return high;
        else return low;
    }
};