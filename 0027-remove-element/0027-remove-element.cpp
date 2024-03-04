class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        
        for(auto it : nums){
            if(it != val){
                nums[ans++] = it;
            }
        }
        
        return ans;
    }
};