class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] res = {Integer.MAX_VALUE, Integer.MIN_VALUE};
        ListNode temp = head.next;
        int mindist = 0;
        int maxdist = 0;
        int count = 1;
        ListNode prev = head;
        while (temp.next != null) {
            count++;
            if ((prev.val > temp.val && temp.next.val > temp.val) || (prev.val < temp.val && temp.next.val < temp.val)) {
                if (mindist != 0) {
                    res[0] = Math.min(res[0], count - mindist);
                }
                mindist = count;
                if (maxdist != 0) {
                    res[1] = Math.max(res[1], count - maxdist);
                }
                if (maxdist == 0) {
                    maxdist = count;
                }
            }
            prev = temp;
            temp = temp.next;
        }
        if (res[0] == Integer.MAX_VALUE && res[1] == Integer.MIN_VALUE) {
            res[0] = -1;
            res[1] = -1;
        }
        return res;
    }
}
