class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> oper = {"+", "-", "*", "/"};
        long first, second;
        
        for(auto it: tokens){
            if(oper.find(it) == oper.end()){
                int num = stoi(it);
                st.push(num);
            }
            
            else{
                second = st.top();
                st.pop();
                
                first = st.top();
                st.pop();
                
                if(it == "+") second = first + second;
                else if(it == "-") second = first - second;
                else if(it == "*") second *= first;
                else if(it == "/") second = first / second;
                
                st.push(second);
            }
            
            
        }
        
        return st.top();
    }
};