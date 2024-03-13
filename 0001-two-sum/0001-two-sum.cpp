class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> mp;
        
        for(int i = 0; i<n; i++){
            if(mp.find(target - nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }
            else{
                return {i,mp[target - nums[i]]};
            }
        }
        return {-1, -1};
    }
};