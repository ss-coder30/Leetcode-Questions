class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> hash;
        int n = nums.size();
        vector<int> ans;
        
        for(const auto& it: nums){
            hash[it]++;
        }
        
        for(const auto& it: hash){
            if(it.second > n/3) ans.emplace_back(it.first);
        }
        
        return ans;
    }
};