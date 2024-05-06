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
    
    int findDia(TreeNode* root, int& dia){
        
        if(root == nullptr){
            return 0;
        }
        
        int leftHeight = findDia(root->left, dia);
        int rightHeight = findDia(root->right, dia);
        
        dia = max(dia, leftHeight + rightHeight);
        
        return 1 + max(leftHeight, rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == nullptr){
            return 0;
        }
        
        int dia = 0;
        
        findDia(root, dia);
        
        return dia;
    }
};