class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash;
        int prefixSum = 0, count = 0;
        hash[0] = 1;
        
        for(int i = 0; i<nums.size(); i++){
            prefixSum +=  nums[i];
            int remove = prefixSum - k;
            count += hash[remove];
            hash[prefixSum] += 1;
        }
        
        return count;
    }
};