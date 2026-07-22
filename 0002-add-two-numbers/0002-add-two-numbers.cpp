class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1); 
        ListNode* temp = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum and the new carry
            int sum = val1 + val2 + carry;
            carry = sum / 10;

            // Create the new node with the single digit and attach it
            temp->next = new ListNode(sum % 10);
            temp = temp->next;

            // Safely advance the pointers if they aren't already null
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy->next; // Return the actual head of the new list
    }
};