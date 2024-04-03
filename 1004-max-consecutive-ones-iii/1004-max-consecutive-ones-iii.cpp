class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // optimal solution
        
        int n = nums.size(), left = 0, right = 0, maxLen = 0, zero = 0;
        
        while(right < n){
            if(nums[right] == 0) zero++;
            
            while(zero > k){
                if(nums[left] == 0) zero--;
                left++;
            }
            
            if(zero <= k){
                int len = right - left + 1;
                maxLen = max(maxLen, len);
            }
            right++;
        }
        
        return maxLen;
    }
};