class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> hash;
        
        for(int i = 0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        
        for(const auto& it: hash){
            if(it.second > 1){
                return it.first;
            }
        }
        
        return -1;
    }
};