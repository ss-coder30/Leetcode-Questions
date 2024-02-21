class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size(), k, l;

        // Find the first index k from the right such that nums[k] < nums[k + 1]
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }

        // If no such index is found, reverse the entire vector
        if (k < 0) {
            std::reverse(nums.begin(), nums.end());
        } 
        else {
            // Find the smallest index l from the right such that nums[l] > nums[k]
            for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 

            // Swap nums[k] and nums[l]
            std::swap(nums[k], nums[l]);

            // Reverse the elements from index k + 1 to the end
            std::reverse(nums.begin() + k + 1, nums.end());
        }
        
    }
};