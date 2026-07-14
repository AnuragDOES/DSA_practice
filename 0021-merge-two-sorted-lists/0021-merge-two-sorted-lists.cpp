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
        ListNode* res = nullptr;
        ListNode* temp = nullptr;
        if(list1 and list2){
            if(list1->val <= list2->val){
            res = list1;
            temp = list1;
            list1 = list1->next;
            }else{
            res = list2;
            temp = list2;
            list2 = list2->next;}
        }else{
            if(!list1) return list2;
            else return list1;
        }
        
        while(list1 and list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        while(list1){
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }
        while(list2){
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
        return res;
    }
};