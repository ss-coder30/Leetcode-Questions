class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char, char>mp;
        set<char> st;
        
        for(int i = 0; i<n; i++){
            if(mp.find(s[i]) == mp.end()){ // not present
                if(st.find(t[i]) != st.end()) return false;
                else{
                    mp[s[i]] = t[i];
                    st.insert(t[i]);
                }
            }
            else{
                if(mp[s[i]] != t[i]) return false;
                else continue;
            }
        }
        
        return true;
    }
};