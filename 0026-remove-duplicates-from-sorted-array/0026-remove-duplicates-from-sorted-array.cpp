class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        
        for(int i = 0; i<nums.size(); i++){
            int x = nums[i];
            s.insert(x);
        }
        
        auto it = s.begin();
        for(int i = 0; i<s.size(); i++){
            nums[i] = *(it);
            it++;
        }
        
        int ans = s.size();
        
        return ans;
    }
};