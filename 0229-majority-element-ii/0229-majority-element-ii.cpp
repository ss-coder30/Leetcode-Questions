class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int count1 = 0, count2 = 0;
        int element1 = INT_MIN, element2 = INT_MIN;
        int n = nums.size();
        vector<int> ans;
        
        for(const auto& it: nums){
            
            if(count1 == 0 && it != element2){
                count1++;
                element1 = it;
            }
            
            else if(count2 == 0 && it != element1){
                count2++;
                element2 = it;
            } 
            
            else if(it == element1) count1++;
            
            else if(it == element2) count2++;
            
            else count1--, count2--;
        }
        
        count1 = 0, count2 = 0;
        
        for(const auto& it: nums){
            if(element1 == it) count1++;
            if(element2 == it) count2++;
        }
        
        int minFreq = (int)(n/3)+1;
        
        if(count1 >= minFreq) ans.emplace_back(element1);
        if(count2 >= minFreq) ans.emplace_back(element2);
        
        return ans;
    }
};