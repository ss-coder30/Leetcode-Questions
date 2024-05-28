class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int hoursSpent = 0;
            
            for (int pile : piles) {
                hoursSpent += (pile + mid - 1) / mid;  // This is equivalent to ceil(pile / mid)
            }
            
            if (hoursSpent <= h) {
                right = mid;  // Try to find a smaller k
            } else {
                left = mid + 1;  // Increase k
            }
        }
        
        return left;  // `left` is the smallest k that works
    }
};
