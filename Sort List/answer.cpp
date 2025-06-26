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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        ListNode* after = mid->next;
        mid->next = NULL;
        ListNode* left = sortList(head);
        after = sortList(after);
        return merge(left,after);
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        if (!head1) return head2;
        if (!head2) return head1;
        ListNode* head = NULL;
        ListNode* prev = NULL;
        if (head1->val <= head2->val) {
            head = head1;
            head1 = head1->next;
        } else {
            head = head2;
            head2 = head2->next;
        }
        prev = head;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                prev->next = head1;
                head1 = head1->next;
            } else {
                prev->next = head2;
                head2 = head2->next;
            }
            prev = prev->next;
        }
        if (head1) prev->next = head1;
        if (head2) prev->next = head2;

        return head;
    }
};
