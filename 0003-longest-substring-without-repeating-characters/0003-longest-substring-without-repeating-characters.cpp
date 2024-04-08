class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char> st;
        int maxLen = 0;
        int i = 0, j = 0; // Use two pointers to track the substring
        
        while (j < n) {
            // If s[j] is not in the set, extend the substring
            if (st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else { // If s[j] is in the set, shrink the substring from the left
                st.erase(s[i]);
                i++;
            }
        }
        
        return maxLen;
    }
};
