class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char>st;
        
        for(int i = 0; i<n; i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top() == s[i]){
                st.pop();
            }
            
            else{
                st.push(s[i]);
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            char c = st.top();
            st.pop();
            ans += c;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};