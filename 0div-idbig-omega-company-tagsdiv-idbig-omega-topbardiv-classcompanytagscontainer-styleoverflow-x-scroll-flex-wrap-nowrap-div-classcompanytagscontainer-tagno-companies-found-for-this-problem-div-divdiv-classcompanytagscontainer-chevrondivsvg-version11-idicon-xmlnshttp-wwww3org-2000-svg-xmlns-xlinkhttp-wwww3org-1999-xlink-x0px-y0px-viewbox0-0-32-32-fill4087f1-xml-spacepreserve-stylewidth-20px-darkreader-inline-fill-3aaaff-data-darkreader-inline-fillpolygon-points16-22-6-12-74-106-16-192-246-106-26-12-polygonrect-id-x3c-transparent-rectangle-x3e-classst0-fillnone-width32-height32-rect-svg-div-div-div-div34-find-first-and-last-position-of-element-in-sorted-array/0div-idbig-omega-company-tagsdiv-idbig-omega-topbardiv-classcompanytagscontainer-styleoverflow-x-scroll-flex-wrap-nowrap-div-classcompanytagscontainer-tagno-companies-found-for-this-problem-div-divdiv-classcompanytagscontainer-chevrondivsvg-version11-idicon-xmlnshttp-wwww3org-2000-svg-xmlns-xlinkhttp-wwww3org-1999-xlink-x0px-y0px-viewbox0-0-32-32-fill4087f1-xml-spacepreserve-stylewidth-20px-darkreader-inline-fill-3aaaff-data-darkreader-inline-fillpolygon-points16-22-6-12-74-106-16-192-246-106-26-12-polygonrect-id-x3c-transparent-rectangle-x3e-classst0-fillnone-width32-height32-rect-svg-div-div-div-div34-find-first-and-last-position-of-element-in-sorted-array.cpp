class Solution {
public:
    
    int lowerBound(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    int upperBound(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = lowerBound(nums, target);
        int last = upperBound(nums, target) - 1;
        
        if(first == n || nums[first] != target){
            return {-1, -1};
        }
        
        
        vector<int> ans = {first, last};
        return ans;
    }
};