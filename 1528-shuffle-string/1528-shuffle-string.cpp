#include <string>
#include <vector>
#include <map>

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        
        map<int, char> m;
        
        for (int i = 0; i < n; i++) {
            m[indices[i]] = s[i];
        }
        
        string ans = "";
        
        for (const auto& it : m) {
            ans += it.second;
        }
        
        return ans;
    }
};
