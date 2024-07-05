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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }

        vector<int> critPts;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        int index = 1; // Start with the second node (index 1)

        while (next != nullptr) {
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                critPts.push_back(index);
            }
            prev = curr;
            curr = next;
            next = next->next;
            index++;
        }

        if (critPts.size() < 2) {
            return {-1, -1};
        }

        int minDis = INT_MAX;
        int maxDis = critPts.back() - critPts.front();

        for (int i = 1; i < critPts.size(); i++) {
            minDis = min(minDis, critPts[i] - critPts[i - 1]);
        }

        return {minDis, maxDis};
    }
};