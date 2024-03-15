class Solution {
public:
    bool isSubsequence(string s, string t) {
        int leftBound = s.size();
        int rightBound = t.size();
        
        int left = 0, right = 0;
        
        while(left < leftBound && right < rightBound){
            if(s[left] == t[right]) left++;
            
            right++;
        }
        
        return (left == leftBound);
    }
};