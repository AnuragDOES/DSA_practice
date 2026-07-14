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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = 0;
        ListNode* fast = head, *slow = head;
        while(fast){
            if(c >= n+1) slow = slow->next;
            fast = fast->next;
            c++;
        }
        if(slow == head and c!=n+1) head = slow->next;
        else{
            slow->next = slow->next->next;
        }
        return head;
    }
};