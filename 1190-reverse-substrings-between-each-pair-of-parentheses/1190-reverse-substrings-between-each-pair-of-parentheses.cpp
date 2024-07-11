class Solution {
public:
    string reverseParentheses(string s) {
        
        int n = s.size();
        vector<int> opened, Pair(n);
        string res;
        
        for(int i = 0; i<n; i++){
            if(s[i] == '(') opened.push_back(i);
            
            if(s[i] == ')'){
                int j = opened.back();
                opened.pop_back();
                Pair[i] = j;
                Pair[j] = i;
            }
        }
        
        for(int i = 0, d = 1; i<n; i+=d){
            if(s[i] == '(' || s[i] == ')'){
                i = Pair[i];
                d = -d;
            }
            else res += s[i];
        }
        
        return res;
    }
};