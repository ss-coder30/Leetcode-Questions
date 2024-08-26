class Solution {
public:
    
    int maxElement(vector<int>& nums){
        int maxi = INT_MIN;
        
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        
        return maxi;
    }
    
    bool isPossible(vector<int>& nums, int div, int threshold){
        long long divSum = 0;
        
        for(int i = 0; i<nums.size(); i++){
            divSum += (nums[i]+div-1) / div;
            
            if(divSum > threshold) return false;
        }
        
        return divSum <= threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int ans = 0;
        
        int low = 1, high = maxElement(nums);
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(isPossible(nums, mid, threshold)){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        
        return ans;
    }
};