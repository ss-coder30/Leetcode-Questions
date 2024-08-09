class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        // optimal solution
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        // to prevent using sets
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<n; i++){
            
            // to remove duplicates
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            for(int j = i+1; j<n; j++){
                
                // to remove duplicates
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                
                // using 2 pointers for remaining 2 numbers
                int k = j+1;
                int l = n-1;
                while(k < l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        
                        // to remove duplicates
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    
                    else if(sum < target) k++;
                    
                    else l--;
                }
            }
        }
        
        return ans;
    }
};