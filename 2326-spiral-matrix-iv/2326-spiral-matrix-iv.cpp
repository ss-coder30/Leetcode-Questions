/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        int left = 0, right = n-1;
        int top = 0, bottom = m-1;
        vector<vector<int>> ans(m, vector<int> (n, -1));
        ListNode* temp = head;
        
        while(temp != nullptr){
            for(int col = left; col <= right && temp != nullptr; col++){
                int value = temp->val;
                ans[top][col] = value;
                temp = temp->next;
            }
            top++;
            
            for(int row = top; row <= bottom && temp != nullptr; row++){
                int value = temp->val;
                ans[row][right] = value;
                temp = temp->next;
            }
            right--;
            
            for(int col = right; col >= left && temp != nullptr; col--){
                int value = temp->val;
                ans[bottom][col] = value;
                temp = temp->next;
            }
            bottom--;
            
            for(int row = bottom; row >= top && temp != nullptr; row--){
                int value = temp->val;
                ans[row][left] = value;
                temp = temp->next;
            }
            left++;
        }
        
        return ans;
    }
};