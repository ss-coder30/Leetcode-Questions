/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        
        ListNode* temp = head;
        unordered_map<ListNode*, int> mp;
        while(temp != nullptr){
            if(mp.find(temp) != mp.end()){
                return temp;
            }
            mp[temp] = 1;
            temp = temp->next;
        }
        return nullptr;
    }
};