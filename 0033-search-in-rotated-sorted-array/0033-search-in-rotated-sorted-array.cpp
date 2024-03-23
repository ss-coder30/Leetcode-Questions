class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int n = nums.size();
        int index;

        // Find the index of the smallest element in the rotated sorted array
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        index = low;

        low = 0;
        high = n - 1;

        // Perform binary search with adjusted indices
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int rotatedMid = (mid + index) % n;

            if (nums[rotatedMid] == target) {
                return rotatedMid;
            } else if (nums[rotatedMid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1; // Return -1 if the target is not found
    }
};
