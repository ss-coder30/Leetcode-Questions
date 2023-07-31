class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            int a=index[i];
            ans.insert(ans.begin()+a,nums[i]);
        }
        ans.erase(ans.begin()+nums.size(),ans.begin()+ans.size());
        return ans;
    }
};