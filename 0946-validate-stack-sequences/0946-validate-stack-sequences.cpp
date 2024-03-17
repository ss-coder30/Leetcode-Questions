class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;
        int j = 0; // Move j outside the loop
        
        for(int i = 0; i < n; i++) {
            int popElement = popped[i];
            
            // Push elements until the current popElement is found
            while(j < n && (st.empty() || st.top() != popElement)) {
                st.push(pushed[j]);
                j++;
            }
            
            // Check if the top element of the stack matches popElement
            if (!st.empty() && st.top() == popElement) {
                st.pop();
            } else {
                return false;
            }
        }
        
        // Check if the stack is empty after processing all elements
        return st.empty();
    }
};
