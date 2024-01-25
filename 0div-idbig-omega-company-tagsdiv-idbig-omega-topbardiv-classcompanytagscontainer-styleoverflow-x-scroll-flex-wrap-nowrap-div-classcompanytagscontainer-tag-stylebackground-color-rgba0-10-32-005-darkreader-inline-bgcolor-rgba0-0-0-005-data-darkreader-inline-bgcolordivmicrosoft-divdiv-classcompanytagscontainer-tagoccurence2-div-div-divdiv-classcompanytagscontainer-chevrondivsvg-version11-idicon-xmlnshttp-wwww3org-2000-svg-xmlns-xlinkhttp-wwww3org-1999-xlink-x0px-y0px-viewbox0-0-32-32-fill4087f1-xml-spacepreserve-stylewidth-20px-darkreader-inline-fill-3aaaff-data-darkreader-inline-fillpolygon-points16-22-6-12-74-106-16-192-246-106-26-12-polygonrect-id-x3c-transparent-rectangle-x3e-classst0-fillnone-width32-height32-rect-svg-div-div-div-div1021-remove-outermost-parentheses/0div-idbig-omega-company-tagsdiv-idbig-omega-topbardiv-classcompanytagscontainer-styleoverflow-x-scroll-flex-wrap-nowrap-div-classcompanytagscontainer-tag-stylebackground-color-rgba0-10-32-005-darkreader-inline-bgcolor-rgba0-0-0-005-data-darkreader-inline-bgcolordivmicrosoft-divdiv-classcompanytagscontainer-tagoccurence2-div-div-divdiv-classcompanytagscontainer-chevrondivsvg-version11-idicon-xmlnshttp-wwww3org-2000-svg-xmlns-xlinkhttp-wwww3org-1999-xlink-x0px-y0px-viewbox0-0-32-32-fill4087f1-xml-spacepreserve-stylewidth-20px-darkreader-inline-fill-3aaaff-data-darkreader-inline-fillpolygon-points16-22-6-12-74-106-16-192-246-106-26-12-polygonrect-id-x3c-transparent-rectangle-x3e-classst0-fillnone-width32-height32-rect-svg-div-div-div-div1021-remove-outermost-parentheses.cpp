class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int n = s.size();
        string ans = "";
        
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                count++;
            }
            else{
                count--;
            }
            
            if((count == 1 && s[i] == '(') || (count == 0 && s[i] == ')')){
                continue;
            }
            else{
                ans += s[i];
            }
        }
        
        return ans;
    }
};