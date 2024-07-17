class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash;
        int ans = 0;
        int sum = 0;
        int rem = 0;
        hash[rem]++;
        
        for(int i = 0; i<nums.size(); i++){
            
            sum += nums[i];
            rem = sum % k;
            if(rem < 0){
                rem += k;
            }
            
            if(hash.find(rem) != hash.end()){
                ans += hash[rem];
            }
            
            hash[rem]++;
        }
        
        return ans;
    }
};