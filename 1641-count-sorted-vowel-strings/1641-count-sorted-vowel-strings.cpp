class Solution {
public:
    int countVowelStrings(int n) {
        
        // maths formula = (k+n-1) C n;
        // k = 5 => formula = (n+4) * (n+3) * (n+2) * (n+1) / 24;
        
        return (n+4) * (n+3) * (n+2) * (n+1) / 24;
    }
};