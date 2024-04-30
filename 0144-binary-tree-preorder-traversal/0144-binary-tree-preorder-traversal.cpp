/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        
        // base case
        if(root == nullptr){
            return preOrder;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            
            // storing top as root and pushing the value in vector
            root = st.top();
            st.pop();
            preOrder.push_back(root->val);
            
            // checking if right and left exists
            if(root->right != nullptr){
                st.push(root->right);
            }
            
            if(root->left != nullptr){
                st.push(root->left);
            }
        }
        
        return preOrder;
    }
};