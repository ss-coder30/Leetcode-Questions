class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        // most optimal solution
        
        int left = 0, right = 0, maxLen = 0, n = fruits.size();
        map<int, int> mp;
        
        while(right < n){
            mp[fruits[right]]++;
            
            if(mp.size() > 2){
                mp[fruits[left]]--;
                
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                
                left++;
            }
            
            else{
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};