class Solution {
    public int minSwaps(int[] nums) {
        int N = nums.length, sum = 0, current = 0, max = 0, left = 0, right = 0;
        for (int b : nums)
            sum += b;
        if (sum == 0 || sum == N)
            return 0;
        while (right < sum)
            current += nums[right++];
        max = current;
        while (left < N) {
            if (right == N)
                right = 0;
            current += nums[right++] - nums[left++];
            max = Math.max(current, max);
        }
        return sum - max;
    }
}
