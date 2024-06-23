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
    
    void calculate(TreeNode* root, vector<int>& ans, int level){
        
        if(root == nullptr) return;
        
        TreeNode* node = root;
            
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        
        calculate(node->right, ans, level+1);
        calculate(node->left, ans, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(root == nullptr) return ans;
        
        calculate(root, ans, 0);
        
        return ans;
    }
};