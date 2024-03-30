class Solution {
public:
    int smallestValue(int n) {
        while(n > 1){
            int sum = 0;
            int d = n;
            for(int i = 2; i <= d; i++){
                while(d%i == 0){
                    sum += i;
                    d /= i;
                }
            }
            
            if(sum == n) return sum;
            n = sum;
        }
        return n;
        
    }
};