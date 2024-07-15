class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> hash;
        set<int> children;

        // Process each description
        for (const auto& it : descriptions) {
            int parent = it[0];
            int child = it[1];
            int isLeft = it[2];
            
            // Mark the child node
            children.insert(child);

            // Create or retrieve the parent node
            if (hash.find(parent) == hash.end()) {
                hash[parent] = new TreeNode(parent);
            }
            TreeNode* parentNode = hash[parent];

            // Create or retrieve the child node
            if (hash.find(child) == hash.end()) {
                hash[child] = new TreeNode(child);
            }
            TreeNode* childNode = hash[child];

            // Connect the child to the parent
            if (isLeft) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
        }

        // Identify the root node
        int rootVal = -1;
        for (const auto& it : descriptions) {
            int parent = it[0];
            if (children.find(parent) == children.end()) {
                rootVal = parent;
                break;
            }
        }

        return hash[rootVal];
    }
};