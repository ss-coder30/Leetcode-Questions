class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        int n = s.size();
        
        for(int i = 0; i<n; i++){
            if(s[i]== '(') st.push(0);
            else{
                int a = st.top();
                st.pop();
                
                if(a == 0) a = 1;
                else a = a*2;
                st.top() += a;
            }
        }
        
        return st.top();
    }
};