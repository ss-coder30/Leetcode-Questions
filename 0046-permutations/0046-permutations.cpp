class Solution {
public:
    
    void helperFunc(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, vector<int> &freq){
        
        // base case if all elements are picked, push ds in ans vector
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                helperFunc(nums, ds, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        
        vector<int> freq(n, 0);
        
        helperFunc(nums, ds, ans, freq);
        
        return ans;
    }
};