class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> hash(256, -1); // to store index of elements
        
        int left = 0, right = 0, maxLen = 0;
        
        while(right < n){
            
            // if s[right] is present in hash
            if(hash[s[right]] != -1){
                if(hash[s[right]] >= left){
                    left = hash[s[right]]+1;
                }
            }
            
            // else get maxLen and update hash array
            int len = right-left+1;
            maxLen = max(maxLen, len);
            hash[s[right]] = right;
            right++;
        }
        
        return maxLen;
    }
};