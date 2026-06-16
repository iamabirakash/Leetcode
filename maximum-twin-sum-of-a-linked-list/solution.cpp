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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* nprev = nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            nprev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        nprev->next = nullptr;
        ListNode* newHead = slow;
        ListNode* prev = nullptr;
        ListNode* temp = newHead;
        while(temp!=nullptr){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        newHead = prev;
        int sum = 0;
        while(head!=nullptr && newHead!=nullptr){
            int currsum = head->val + newHead->val;
            sum = max(sum,currsum);
            head = head->next;
            newHead = newHead->next;
        }
        return sum;
    }
};