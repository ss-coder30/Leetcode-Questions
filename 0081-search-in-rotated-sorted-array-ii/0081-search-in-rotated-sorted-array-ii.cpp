class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target) return true;
            
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            
            // left half is sorted
            if(nums[low] <= nums[mid]){
                
                // target exists
                if(nums[low] <= target && target < nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            
            // right half is sorted
            else {
                // if exists
                if(nums[mid] < target && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        
        return false;
        
    }
};