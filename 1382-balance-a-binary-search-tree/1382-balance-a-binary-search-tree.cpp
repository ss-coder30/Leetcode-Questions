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
    
    void inTraverse(TreeNode* root, vector<int>& inOrder){
        
        if(root == nullptr) return;
        
        inTraverse(root->left, inOrder);
        inOrder.push_back(root->val);
        inTraverse(root->right, inOrder);
    }
    
    TreeNode* constructBST(vector<int>& inOrder, int low, int high){
        
        if(low > high) return nullptr;
        
        int mid = low + (high - low)/2;
        
        TreeNode* curr = new TreeNode(inOrder[mid]);
        curr->left = constructBST(inOrder, low, mid-1);
        curr->right = constructBST(inOrder, mid+1, high);
        
        return curr;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        if(root == nullptr) nullptr;
        
        vector<int> inOrder;        
        inTraverse(root, inOrder);
        
        return constructBST(inOrder, 0, inOrder.size()-1);
    }
};