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
    
    TreeNode* buildTreePostIn(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int>& hash){
        
        // base case
        if(postStart > postEnd || inStart > inEnd) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRoot = hash[postorder[postEnd]];
        int numsLeft = inRoot - inStart;
        
        root->left = buildTreePostIn(inorder, inStart, inRoot-1, postorder,                         postStart, postStart + numsLeft - 1, hash);
        
        root->right = buildTreePostIn(inorder, inRoot+1, inEnd, postorder,                           postStart + numsLeft, postEnd-1, hash);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        // base case
        if(inorder.size() != postorder.size()) return nullptr;
        
        map<int, int> hash;
        
        for(int i = 0; i<inorder.size(); i++){
            hash[inorder[i]] = i;
        }
        
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, hash);
        
    }
};