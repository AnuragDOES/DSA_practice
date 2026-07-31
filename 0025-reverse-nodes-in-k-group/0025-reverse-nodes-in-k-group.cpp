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
    ListNode* reverseHelp(ListNode* first, ListNode* last){
        ListNode* prev = last;
        ListNode* temp = first, *nextNode = first;
        while(temp!=last){
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* dummy = new ListNode(0), *start = dummy;
        dummy->next = head;
        ListNode* curr = head;
        while(curr){
            curr=curr->next;
            count++;
            if(count % k == 0){
                ListNode* first = start->next;
                start->next = reverseHelp(first, curr);
                start = first;
            }
        }
        return dummy->next;
    }
};