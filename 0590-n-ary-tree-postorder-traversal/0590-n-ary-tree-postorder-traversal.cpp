/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        
        vector<int> ans;
        
        // base case
        if(root == nullptr) return ans;
        
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()){
            Node* temp = st.top();
            st.pop();
            
            for(int i = 0; i<temp->children.size(); i++){
                st.push(temp->children[i]);
            }
            
            ans.push_back(temp->val);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};