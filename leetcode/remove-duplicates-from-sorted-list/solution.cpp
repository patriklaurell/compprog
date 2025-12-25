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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* left = head;
        ListNode* mid = head->next;
        ListNode* right = head->next->next;

        while (mid != nullptr) {
            if (left->val == mid->val) {
                while (mid != nullptr && left->val == mid->val) {
                    mid = mid->next == nullptr ? nullptr : mid->next;
                }
                left = mid;
                mid = mid == nullptr ? mid : mid->next;
                right = mid == nullptr ? mid : mid->next;
            } else {
                break;
            }
        }

        head = left;

        if (head == nullptr || head->next == nullptr) 
            return head;
        
        while (right != nullptr) {
            if (right->val == mid->val) {
                while (mid != nullptr && mid->val == right->val) {
                    mid = mid->next;
                }
                right = mid == nullptr ? mid : mid->next;
            } else {
                left->next = mid;
                left = mid;
                mid = right;
                right = right == nullptr ? right : right->next;
            }  
        }

        left->next = mid;

        return head;
    }
};
