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
        ListNode* res = new ListNode();
        int carry = 0;
        ListNode* temp = res;
        while(l1 and l2){
            ListNode* node = new ListNode();
            temp->next = node;
            temp = temp->next;
            int sum = l1->val + l2->val + carry;
            temp->val = sum%10;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            ListNode* node = new ListNode();
            temp->next = node;
            temp = temp->next;
            int sum = l1->val + carry;
            temp->val = sum%10;
            carry = sum/10;
            l1 = l1->next;
        }
        while(l2){
            ListNode* node = new ListNode();
            temp->next = node;
            temp = temp->next;
            int sum = l2->val + carry;
            temp->val = sum%10;
            carry = sum/10;
            l2 = l2->next;
        }
        if(carry){
            ListNode* node = new ListNode();
            temp->next = node;
            temp = temp->next;
            temp->val = carry;
        }
        return res->next;
    }
};