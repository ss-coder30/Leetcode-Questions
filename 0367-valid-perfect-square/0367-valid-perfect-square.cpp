class Solution {
public:
    bool isPerfectSquare(int num) {
        int d = sqrt(num);
        
        return (d*d == num);
    }
};