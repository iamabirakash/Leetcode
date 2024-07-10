class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int length1 = nums1.length;
        int length2 = nums2.length;
        int[] result = new int[length1 + length2];
        for (int i = 0; i < length1; i++) {
            result[i] = nums1[i];
        }
        for (int i = 0; i < length2; i++) {
            result[length1 + i] = nums2[i];
        }
        Arrays.sort(result);

        int start = 0;
        int end = result.length;
        Arrays.sort(result);
        int mid = start + (end - start) / 2;
        if (result.length % 2 == 0) {
             double ans = (result[mid] + result[mid - 1]) / 2.0;
            return ans;
        }
        return result[mid];
    }
}
