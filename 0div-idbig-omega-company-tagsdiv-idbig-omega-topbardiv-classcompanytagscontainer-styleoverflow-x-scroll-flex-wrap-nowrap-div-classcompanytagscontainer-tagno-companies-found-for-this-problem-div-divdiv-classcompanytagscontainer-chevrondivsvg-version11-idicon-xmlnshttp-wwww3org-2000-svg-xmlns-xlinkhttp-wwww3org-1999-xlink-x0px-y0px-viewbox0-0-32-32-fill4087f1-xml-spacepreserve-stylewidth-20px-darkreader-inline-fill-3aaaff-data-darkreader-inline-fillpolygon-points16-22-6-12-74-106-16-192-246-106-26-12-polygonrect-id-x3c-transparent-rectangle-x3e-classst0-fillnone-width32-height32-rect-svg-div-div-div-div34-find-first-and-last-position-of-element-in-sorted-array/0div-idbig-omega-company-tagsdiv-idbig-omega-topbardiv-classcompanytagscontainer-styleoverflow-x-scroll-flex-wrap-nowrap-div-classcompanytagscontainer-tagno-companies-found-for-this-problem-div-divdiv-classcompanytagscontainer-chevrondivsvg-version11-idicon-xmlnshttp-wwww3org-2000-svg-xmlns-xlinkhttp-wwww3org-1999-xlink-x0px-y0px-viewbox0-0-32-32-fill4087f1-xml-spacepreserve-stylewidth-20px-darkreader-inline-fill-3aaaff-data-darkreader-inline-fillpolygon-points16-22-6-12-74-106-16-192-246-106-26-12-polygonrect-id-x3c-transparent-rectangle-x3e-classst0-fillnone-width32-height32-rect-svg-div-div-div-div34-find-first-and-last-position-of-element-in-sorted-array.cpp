class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i<n; i++){
            
            if(nums[i] == target){
                if(first == -1){
                    first = i;
                }
                last = i;
            }
        }
        ans.emplace_back(first);
        ans.emplace_back(last);
        
        return ans;
    }
};