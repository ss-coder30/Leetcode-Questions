class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> postOrder;
        TreeNode* curr = root;
        TreeNode* prev = nullptr; // To keep track of the previously visited node

        while (curr != nullptr || !st.empty()) {
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            } 
            
            else {
                TreeNode* temp = st.top()->right;
                
                if (temp == nullptr || temp == prev) {
                    prev = st.top();
                    st.pop();
                    postOrder.push_back(prev->val);
                } 
                
                else {
                    curr = temp;
                }
            }
        }
        return postOrder;
    }
};
