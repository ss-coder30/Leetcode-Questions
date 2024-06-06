class Solution {
public:
    
    bool isNumeric(string s) {
        if (s.empty()) return false;
        if (s[0] == '-') {
            return s.size() > 1 && std::all_of(s.begin() + 1, s.end(), ::isdigit);
        }
        return std::all_of(s.begin(), s.end(), ::isdigit);
    }
    
    int calPoints(vector<string>& operations) {
        int score = 0;
        stack<int> st;
        
        for (const string& op : operations) {
            if (isNumeric(op)) {
                int x = stoi(op);
                st.push(x);
            } else if (op == "C") {
                if (!st.empty()) st.pop();
            } else if (op == "D") {
                if (!st.empty()) st.push(2 * st.top());
            } else if (op == "+") {
                int last = 0, secondLast = 0;
                if (!st.empty()) {
                    last = st.top(); st.pop();
                }
                if (!st.empty()) {
                    secondLast = st.top();
                    st.push(last);
                }
                st.push(last + secondLast);
            }
        }
        
        // Sum up all the values in the stack
        while (!st.empty()) {
            score += st.top();
            st.pop();
        }
        
        return score;
    }
};
