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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Check if either list is empty
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        
        // Create a dummy node to hold the merged list
        ListNode* sorted = new ListNode(-1);
        ListNode* sortedHead = sorted;
        
        // Merge the lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                sorted->next = list1;
                list1 = list1->next;
            } else {
                sorted->next = list2;
                list2 = list2->next;
            }
            sorted = sorted->next;
        }
        
        // Append any remaining nodes from list1
        while (list1 != nullptr) {
            sorted->next = list1;
            list1 = list1->next;
            sorted = sorted->next;
        }
        
        // Append any remaining nodes from list2
        while (list2 != nullptr) {
            sorted->next = list2;
            list2 = list2->next;
            sorted = sorted->next;
        }
        
        // Store the head of the merged list
        ListNode* result = sortedHead->next;
        
        // Delete the dummy node
        delete sortedHead;
        
        return result;
    }
};