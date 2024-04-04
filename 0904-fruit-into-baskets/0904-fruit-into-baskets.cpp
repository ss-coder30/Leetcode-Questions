class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, maxLen = 0, n = fruits.size();
        map<int, int> mp;
        
        while(right < n){
            mp[fruits[right]]++;
            
            if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[left]]--;
                    if(mp[fruits[left]] == 0){
                        mp.erase(fruits[left]);
                    }
                    left++;
                }
            }
            
            if(mp.size() <= 2){
                maxLen = max(maxLen, right - left +1);
            }
            right++;
        }
        
        return maxLen;
        
    }
};