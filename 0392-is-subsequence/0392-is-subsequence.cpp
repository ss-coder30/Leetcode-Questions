class Solution {
public:
    
    bool checkSubSequence(int leftIndex, int rightIndex, string s, string t){
        int leftBound = s.size();
        int rightBound = t.size();
        
        if(leftIndex == leftBound) return true;
        
        if(rightIndex == rightBound) return false;
           
        if(s[leftIndex] == t[rightIndex]){
            leftIndex++;
        }
        rightIndex++;
           
        return checkSubSequence(leftIndex, rightIndex, s, t);
    }
    
    bool isSubsequence(string s, string t) {
        int leftIndex = 0, rightIndex = 0;
        int sSize = s.size();
        int tSize = t.size();
        
        return checkSubSequence(0, 0, s, t);
    }
};