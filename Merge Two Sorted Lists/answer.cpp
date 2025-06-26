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
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* head = NULL;
        ListNode* prev = NULL;
        if(list1->val <= list2->val){
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        prev = head;
        while(list1 && list2){
            if(list1->val <= list2->val){
                prev->next=list1;
                list1 = list1->next;
            } else {
                prev->next=list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        if(list1) prev->next = list1;
        if(list2) prev->next = list2;
        return head;
    }
};
