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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        ListNode* curr = head;
        int cnt = 1;
        while(curr->next){
            cnt++;
            curr = curr->next;
        }
        int count = 0;
        int rotate = k%cnt;
        curr->next = head;
        ListNode* start  = head;
        for(int i=1;i<cnt-rotate;i++){
            start = start->next;
        }
        ListNode* newHead = start->next;
        start->next = NULL;
        return newHead;
    }
};