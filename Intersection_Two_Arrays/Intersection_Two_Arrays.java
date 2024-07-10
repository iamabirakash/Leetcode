
package Leetcode;
import java.util.*;

public class intersection_of_two_arrays {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        int i = 0, j = 0;
        int k = 0;
        int[] temp = new int[Math.min(nums1.length, nums2.length)];
        
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                temp[k++] = nums1[i];
                i++;
                j++;
            }
        }
        int[] result = new int[k];
        System.arraycopy(temp, 0, result, 0, k);
        return result;
    }

    public static void main(String[] args) {
        // int[] nums1 = {12, 3456, 2, 6, 7896};
        // int[] nums2 = {10, 12, 2, 5, 796};
        // int result = intersect(nums1,nums2);
        // System.out.println("The number of integers with an even number of digits is: " + result); // Output: 2

        intersection_of_two_arrays solution = new intersection_of_two_arrays();
        int[] nums1 = {1, 2, 2, 1}; // Example array 1
        int[] nums2 = {2, 2};       // Example array 2
        int[] result = solution.intersect(nums1, nums2);
        System.out.println("Intersection: " + Arrays.toString(result));
    }
}
