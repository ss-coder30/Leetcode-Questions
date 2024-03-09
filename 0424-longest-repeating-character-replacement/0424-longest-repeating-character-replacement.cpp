class Solution {
public:
    
    bool canMakeValidSubstring(string s, int length, int k){
        vector<int> freqMap(26, 0);
        int left = 0;
        int maxFreq = 0;
        
        for(int right = 0; right < s.size(); right++){
            freqMap[s[right] - 'A']++;
            
            if(right - left + 1 > length){
                freqMap[s[left] - 'A']--;
                left++;
            }
            
            maxFreq = max(maxFreq, freqMap[s[right] - 'A']);
            
            if(length - maxFreq <= k) return true;
        }
        return false;
    }
    
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0, high = n+1;
        
        while(high - low > 1){
            int mid = (high + low)/2;
            if(canMakeValidSubstring(s, mid, k)){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        
        if(canMakeValidSubstring(s, low, k)) return low;
        else return high;
    }
};