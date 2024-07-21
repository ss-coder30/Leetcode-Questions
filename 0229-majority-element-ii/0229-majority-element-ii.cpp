class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> hash;
        int n = nums.size();
        vector<int> ans;
        int minFreq = (n/3)+1;
        
        for(const auto& it: nums){
            hash[it]++;
            
            if(hash[it] == minFreq) ans.push_back(it);
        }
        
        return ans;
    }
};