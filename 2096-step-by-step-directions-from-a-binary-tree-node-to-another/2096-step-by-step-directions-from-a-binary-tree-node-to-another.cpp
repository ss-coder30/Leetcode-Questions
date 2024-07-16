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
    bool findPath(TreeNode* root, int val, string& path){
        if(root->val == val) return true;
        
        if(root->left != nullptr && findPath(root->left, val, path)){
            path.push_back('L');
        }
        
        else if(root->right != nullptr && findPath(root->right, val, path)){
            path.push_back('R');
        }
        
        return !path.empty();
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string startPath, destPath;
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);
        
        while(!startPath.empty() && !destPath.empty() && startPath.back() == destPath.back()){
            startPath.pop_back();
            destPath.pop_back();
        }
        
        return string(startPath.size(), 'U') + string(rbegin(destPath), rend(destPath));
    }
};