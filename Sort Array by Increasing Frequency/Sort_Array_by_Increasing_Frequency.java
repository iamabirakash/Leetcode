class Solution {
     public static int[] frequencySort(int[] nums) {
        Map<Integer, Integer> map = new TreeMap<>();
        int[] arr = new int[nums.length];
        List<Integer> list = new ArrayList<>();
        for (int i : nums) {
            if (map.get(i) == null) {
                map.put(i, 1);
            } else {
                int count = map.get(i);
                map.put(i, count + 1);
            }
        }
        Set<Integer> set = new TreeSet<>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            set.add(entry.getValue());
        }
        for (int i : set) {

            List<Integer> list2 = new ArrayList<>();
            for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
                if (entry.getValue() == i) {
                    list2.add(entry.getKey());
                }
            }
            Collections.sort(list2,Collections.reverseOrder());
            for(int j:list2){
               int k=map.get(j);
               for(int m=0;m<k;m++){
                   list.add(j);
               }
            }
        }

        for(int i=0;i<list.size();i++){
            arr[i]=list.get(i);
        }
        return arr;
    }
}

// class Solution {
//     public int[] frequencySort(int[] nums) {
//         int[] count=new int[202];
//         for(int i=0;i<nums.length;i++){
//             count[nums[i]+100]++;
//         }
//         quickSort(nums,count,0,nums.length-1);
//         return nums;
//     }
//     void quickSort(int[] nums,int freq[],int low,int high){
//         if(low<high){
//             int pivot=partition(nums,freq,low,high);
//             quickSort(nums,freq,low,pivot-1);
//             quickSort(nums,freq,pivot+1,high);
//         }
//     }
//     int partition(int[] nums,int freq[],int low,int high){
//         int pivot=freq[nums[high]+100];
//         int i=low-1;
//         for(int j=low;j<high;j++){
//             if(pivot > freq[nums[j]+100]){
//                 i++;
//                 int temp=nums[j];
//                 nums[j]=nums[i];
//                 nums[i]=temp;
//             }else if(freq[nums[j]+100]==pivot){
//                 if(nums[high]<=nums[j]){
//                     i++;
//                     int temp=nums[j];
//                     nums[j]=nums[i];
//                     nums[i]=temp;
//                 }
//             }
//         }
//         int temp=nums[i+1];
//         nums[i+1]=nums[high];
//         nums[high]=temp;
//         return i+1;
//     }
// }
