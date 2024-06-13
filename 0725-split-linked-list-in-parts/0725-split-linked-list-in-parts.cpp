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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> ans(k, 0);
        int length = 0;
        
        ListNode* temp = head;
        while(temp != nullptr){
            length++;
            temp = temp->next;
        }
        
        int equalSize = length / k;
        int extraNodes = length % k;
        
        temp = head;
        ListNode* prev = nullptr;
        
        for(int i = 0; temp && i < k; i++,extraNodes--){
            ans[i] = temp;
            
            for(int j = 0; j < equalSize + (extraNodes > 0); j++){
                prev = temp;
                temp = temp->next;
            }
            
            prev->next = nullptr;
        }
        
        return ans;
    }
};