class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> diff(n);
        
        // Calculate the total sum of the array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // Calculate the left sum for each index
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            diff[i] = abs(leftSum - (totalSum - leftSum - nums[i]));
            leftSum += nums[i];
        }
        
        return diff;
    }
};