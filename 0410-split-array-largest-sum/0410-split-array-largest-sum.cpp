class Solution {
public:
    
    int countSubarrays(vector<int>& nums, int sum){
        int count = 1;
        long long subarraySum = 0;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            if(subarraySum + nums[i] <= sum){
                subarraySum += nums[i];
            }
            
            else {
                count++;
                subarraySum = nums[i];
            }
        }
        
        return count;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(countSubarrays(nums, mid) > k){
                low = mid+1;
            }
            else {
                high = mid-1;
                ans = mid;
            }
        }
        
        return ans;
    }
};