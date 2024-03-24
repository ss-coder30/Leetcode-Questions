class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2){
            return 0;
        }
        
        vector<int>prime(n, 0);
        
        for(int i = 2; i<n; i++){
            if(prime[i] == 0){
                for(int j = 2*i; j<n; j += i){
                    prime[j] = 1;
                }
            }
        }
        
        int count = 0;
        for(int i = 2; i<n; i++){
            if(prime[i] == 0) count++;
        }
        return count;
    }
};