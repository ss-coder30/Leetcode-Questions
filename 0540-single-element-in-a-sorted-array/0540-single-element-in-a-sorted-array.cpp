class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0, high = n-1;
        
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            // edge cases
            if(n == 1) return nums[0];
            
            if(mid == 0) {
                if(nums[mid] != nums[mid+1]) return nums[mid];
            }
            
            if(mid == n-1){
                if(nums[mid] != nums[mid-1]) return nums[mid];
            }
            
            if(nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            
            // checking for left half
            if((mid % 2 == 0 and nums[mid] == nums[mid+1]) or (mid % 2 != 0 and nums[mid] == nums[mid-1])){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        
        return -1;
    }
};