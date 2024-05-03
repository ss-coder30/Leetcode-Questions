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
    int maxDepth(TreeNode* root) {
        // bfs approach
        
        // base case
        if(root == nullptr){
            return 0;
        }
        
        queue<TreeNode*>q;
        int height = 0;
        
        q.push(root);
        
        while(!q.empty()){
            int count = q.size();
            
            for(int i = 0; i<count; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != nullptr){
                    q.push(node->left);
                }
                
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            
            height++;
        }
        
        return height;
    }
};