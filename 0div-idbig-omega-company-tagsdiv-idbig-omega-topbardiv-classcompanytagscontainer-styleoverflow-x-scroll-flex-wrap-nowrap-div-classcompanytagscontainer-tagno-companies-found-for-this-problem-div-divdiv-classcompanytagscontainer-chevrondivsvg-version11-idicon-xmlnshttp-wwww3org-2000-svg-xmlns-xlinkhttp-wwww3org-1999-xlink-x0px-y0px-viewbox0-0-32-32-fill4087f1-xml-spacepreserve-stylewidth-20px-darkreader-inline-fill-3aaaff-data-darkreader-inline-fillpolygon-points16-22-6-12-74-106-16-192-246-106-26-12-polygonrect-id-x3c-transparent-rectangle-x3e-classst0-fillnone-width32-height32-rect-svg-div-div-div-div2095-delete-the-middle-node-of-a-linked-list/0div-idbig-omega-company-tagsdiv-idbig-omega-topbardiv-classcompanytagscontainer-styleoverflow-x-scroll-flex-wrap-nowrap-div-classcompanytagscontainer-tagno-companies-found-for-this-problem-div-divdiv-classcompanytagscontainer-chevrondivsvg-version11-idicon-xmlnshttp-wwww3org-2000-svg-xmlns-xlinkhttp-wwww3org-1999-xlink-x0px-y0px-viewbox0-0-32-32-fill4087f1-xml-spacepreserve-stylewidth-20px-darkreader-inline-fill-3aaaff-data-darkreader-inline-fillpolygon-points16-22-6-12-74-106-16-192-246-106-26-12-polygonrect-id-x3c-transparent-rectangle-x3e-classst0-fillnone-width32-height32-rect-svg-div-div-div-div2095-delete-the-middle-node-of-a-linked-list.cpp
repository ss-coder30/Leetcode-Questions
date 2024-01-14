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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
        // If the list is empty or has only one element, there is no middle to delete
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // At this point, 'slow' is pointing to the middle, and 'prev' is pointing to the node before the middle.

    if (prev != nullptr) {
        // If 'prev' is not null, update its next pointer to skip the middle node.
        prev->next = slow->next;
    } else {
        // If 'prev' is null, it means the middle is the head, so update the head.
        head = slow->next;
    }

    // Delete the middle node.
    delete slow;

    return head;
    }
};