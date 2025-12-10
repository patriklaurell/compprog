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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out = new ListNode();
        ListNode* out_start = out;

        int carry = 0;
        int x = 0;
        int y = 0;
        while (true) {
            if (l1 == nullptr && l2 == nullptr) {
                if (carry != 0) {
                    out->next = new ListNode(carry);
                }
                return out_start;
            }

            if (l1 != nullptr) {
                x = l1->val;
            }

            if (l2 != nullptr) {
                y = l2->val;
            }
            printf(x = %i, y = %i, carry = %in, x,y,carry);

            int sum = x + y + carry;

            printf(sum = %in, sum);

            if (sum < 10) {
                out->val = sum;
                carry = 0;
            } else {
                out->val = sum - 10;
                carry = 1;
            }
            printf(out- = %in, out->val);

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }

            if (l1 != nullptr || l2 != nullptr) {
                out->next = new ListNode();
                out = out->next;
            }
            
            x = 0;
            y = 0;
        } 
    }
};
