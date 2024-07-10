package Leetcode;

import java.util.Arrays;

public class minimum_difference {
    public int minDifference(int[] nums) {
        int n = nums.length;
        if (n <= 4) {
            return 0; // If there are 4 or fewer elements, we can make all elements equal in at most 3 moves
        }
        Arrays.sort(nums); // Sort the array
        // Calculate the possible minimum differences

        int minDiff = Integer.MAX_VALUE;
        minDiff = Math.min(minDiff, nums[n - 1] - nums[3]); // Remove the 3 smallest
        minDiff = Math.min(minDiff, nums[n - 2] - nums[2]); // Remove the 2 smallest and 1 largest
        minDiff = Math.min(minDiff, nums[n - 3] - nums[1]); // Remove the 1 smallest and 2 largest
        minDiff = Math.min(minDiff, nums[n - 4] - nums[0]); // Remove the 3 largest

        return minDiff;
    }
    public static void main(String[] args) {
        minimum_difference solution = new minimum_difference();
        int[] nums = {1,5,0,10,14}; // Example array
        int result = solution.minDifference(nums);
        System.out.println("Minimum difference: " + result);
    }
}
