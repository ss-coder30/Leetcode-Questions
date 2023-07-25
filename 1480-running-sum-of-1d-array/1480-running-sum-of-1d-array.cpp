class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i<n; i++){
            int sum = nums[i];
            for(int j = 0; j<i; j++){
                sum += nums[j];
                
            }
            int x = sum;
            ans.push_back(x);
        }
        return ans;
    }
};