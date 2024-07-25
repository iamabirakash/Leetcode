class Solution {
    public int[] sortArray(int[] nums) {
        // int small = nums[0];
        // for(int i=0;i<nums.length;i++){
        //     for(int j=i+1;j<nums.length;j++){
        //         if(nums[i]>nums[j]){
        //             int temp = nums[i];
        //             nums[i] = nums[j];
        //             nums[j] = temp;
        //         }
        //     }
        // }
        // return nums;

        Arrays.sort(nums);
        return nums;
    }
}