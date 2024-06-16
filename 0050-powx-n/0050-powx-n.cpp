class Solution {
public:
    double myPow(double x, int n) {
        // Base case for negative exponent
        if (n < 0) {
            x = 1 / x;
            // Use a long variable to handle the overflow issue when n == INT_MIN
            return powRecursive(x, -(long)n);
        }
        return powRecursive(x, n);
    }
    
private:
    double powRecursive(double x, long n) {
        // Base cases
        if (n == 0) return 1;
        if (n == 1) return x;
        
        // Recursively calculate half power
        double half = powRecursive(x, n / 2);
        
        // Combine results
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};
