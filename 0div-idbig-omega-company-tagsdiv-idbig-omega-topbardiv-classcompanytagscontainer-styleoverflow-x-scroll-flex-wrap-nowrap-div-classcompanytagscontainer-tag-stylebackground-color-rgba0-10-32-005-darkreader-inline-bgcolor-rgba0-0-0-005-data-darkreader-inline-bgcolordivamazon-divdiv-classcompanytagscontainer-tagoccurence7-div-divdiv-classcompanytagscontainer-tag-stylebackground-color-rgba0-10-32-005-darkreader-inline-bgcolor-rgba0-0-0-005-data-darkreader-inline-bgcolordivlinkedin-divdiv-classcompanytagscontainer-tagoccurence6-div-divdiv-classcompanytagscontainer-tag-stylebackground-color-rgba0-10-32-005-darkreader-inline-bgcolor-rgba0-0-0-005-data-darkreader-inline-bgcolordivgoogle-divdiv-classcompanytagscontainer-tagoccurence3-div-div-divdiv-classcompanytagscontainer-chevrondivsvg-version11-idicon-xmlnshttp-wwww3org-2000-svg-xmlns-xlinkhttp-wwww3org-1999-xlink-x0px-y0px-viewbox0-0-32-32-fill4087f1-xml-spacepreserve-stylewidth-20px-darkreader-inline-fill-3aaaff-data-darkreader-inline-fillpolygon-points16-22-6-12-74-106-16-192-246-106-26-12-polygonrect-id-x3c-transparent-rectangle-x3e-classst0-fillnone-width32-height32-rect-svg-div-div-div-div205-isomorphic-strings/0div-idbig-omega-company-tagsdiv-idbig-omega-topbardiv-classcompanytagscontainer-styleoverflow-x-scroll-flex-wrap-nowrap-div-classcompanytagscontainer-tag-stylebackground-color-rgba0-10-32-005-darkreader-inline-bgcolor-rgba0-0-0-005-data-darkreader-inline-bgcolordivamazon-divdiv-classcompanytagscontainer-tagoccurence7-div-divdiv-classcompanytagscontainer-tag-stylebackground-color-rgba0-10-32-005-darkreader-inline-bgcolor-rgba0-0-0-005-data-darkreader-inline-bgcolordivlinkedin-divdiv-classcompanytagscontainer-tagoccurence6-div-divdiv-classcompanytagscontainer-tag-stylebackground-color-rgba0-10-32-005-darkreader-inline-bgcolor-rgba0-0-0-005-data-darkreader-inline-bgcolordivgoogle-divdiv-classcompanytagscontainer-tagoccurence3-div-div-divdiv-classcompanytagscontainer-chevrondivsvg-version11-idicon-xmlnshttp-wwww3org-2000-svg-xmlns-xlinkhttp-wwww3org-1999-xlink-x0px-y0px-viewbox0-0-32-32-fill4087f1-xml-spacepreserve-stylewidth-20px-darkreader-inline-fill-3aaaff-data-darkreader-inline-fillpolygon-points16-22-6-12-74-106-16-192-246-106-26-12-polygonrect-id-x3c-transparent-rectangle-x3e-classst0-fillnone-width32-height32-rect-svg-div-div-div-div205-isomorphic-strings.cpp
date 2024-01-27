class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<char> s_t(128, 0), t_s(128, 0);
        
        for(int i = 0; i < s.size(); i++) {
            // If either mapping is already established
            if(s_t[s[i]] != 0 || t_s[t[i]] != 0) {
                // Check if the mappings are consistent
                if(s_t[s[i]] != t[i] || t_s[t[i]] != s[i])
                    return false;
            }
            else {
                // Establish the mappings
                s_t[s[i]] = t[i];
                t_s[t[i]] = s[i];
            }
        }
        return true;
    }
};