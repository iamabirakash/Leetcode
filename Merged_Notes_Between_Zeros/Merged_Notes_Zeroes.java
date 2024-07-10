class Solution {
    public ListNode mergeNodes(ListNode head) {
        if(head==null || head.next==null) return null;

        int sum = 0;
        ListNode dummy = new ListNode(0);
        ListNode st = dummy; 
        ListNode curr = head.next;

        while(curr!=null){
            if(curr.val==0){
                dummy.next = new ListNode(sum);
                dummy = dummy.next; 
                sum = 0;
            }

            sum += curr.val;

            curr = curr.next;

        }

        return st.next;
    }
}
