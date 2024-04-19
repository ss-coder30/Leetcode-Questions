class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        sort(strs.begin(), strs.end());
        
        int firstSize = strs[0].size();
        int lastSize = strs[n-1].size();
    
        
        int m = min(firstSize, lastSize);
        string ans = "";
        
        for(int i = 0; i<m; i++){
            if(strs[0][i] != strs[n-1][i]){
                break;
            }
            else{
                ans += strs[0][i];
            }
        }
        return ans;
        
    }
};