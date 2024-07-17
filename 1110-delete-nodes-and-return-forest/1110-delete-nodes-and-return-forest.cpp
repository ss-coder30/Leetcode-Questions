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
    
private:
    TreeNode* helper(TreeNode* node, vector<TreeNode*>& result, set<int>& toDelete, bool isRoot){
        
        if(node == nullptr) return nullptr;
        
        bool deleted = toDelete.find(node->val) != toDelete.end();
        
        if(isRoot && !deleted) result.push_back(node);
        
        node->left = helper(node->left, result, toDelete, deleted);
        node->right = helper(node->right, result, toDelete, deleted);
        
        return deleted ? nullptr : node;
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*> result;
        set<int> toDelete;
        
        for(const auto& it: to_delete){
            toDelete.insert(it);
        }
        
        helper(root, result, toDelete, true);
        
        return result;
    }
};