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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while (curr) {
            st.push(curr);
            curr = curr->next;
        }
        ListNode* newHead = NULL;
        int maxSoFar = INT_MIN;
        while (!st.empty()) {
            ListNode* node = st.top();
            st.pop();

            if (node->val >= maxSoFar) {
                node->next = newHead;
                newHead = node;
                maxSoFar = node->val;
            }
        }
        return newHead;
        // if(head==NULL) return 0;
        // ListNode* temp = head->next;
        // ListNode* t = head;
        // ListNode* tempHead = head;
        // while(t!=NULL){
        //     if(temp==NULL){
        //         t = t->next;
        //         temp = t->next;
        //     } else if(t->val<temp->val){
        //         if(tempHead == head){
        //             tempHead = temp;
        //         } else {
        //             tempHead->next = temp;
        //         }
        //         t = temp;
        //         temp=t;
        //     }
        //     temp = temp->next;
        // }
        // return tempHead;
    }
};
