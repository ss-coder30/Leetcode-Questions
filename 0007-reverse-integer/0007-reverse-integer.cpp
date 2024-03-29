class Solution {
public:
    int reverse(int x) {
        
        long int ans = 0;
        while(x >=1 || x<=-1){
            int lastDigit = x%10;
            x = x/10;
            ans = (ans*10)+lastDigit;
        }
        if(ans > INT_MAX || ans < INT_MIN){
            return 0;
        }
        return ans;
    }
};