class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        
        unordered_map<int, int> hash;
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            hash[nums[i]]++;
        }
        
        for(auto it: hash){
            if(hash.find(it.first - diff) != hash.end() && hash.find(it.first + diff) != hash.end()){
                ans++;
            }
        }
        
        return ans;
    }
};