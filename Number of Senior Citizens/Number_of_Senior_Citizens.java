class Solution {

    public int countSeniors(String[] details) {
        int seniorCount = 0;

        // Iterate through each passenger's details
        for (String passengerInfo : details) {
            // Extract the digits of age
            int ageTens = passengerInfo.charAt(11) - '0';
            int ageOnes = passengerInfo.charAt(12) - '0';

            // Calculate the full age
            int age = ageTens * 10 + ageOnes;

            // Check if the passenger is a senior (strictly over 60 years old)
            if (age > 60) {
                seniorCount++;
            }
        }

        return seniorCount;
    }
}

// class Solution {
//     public int countSeniors(String[] details) {
//         List <Integer> arr=new ArrayList<>();
//         for(String i:details)
//         {
//          arr.add(Integer.parseInt(i.substring(11,13)));
//         }
//         int count=0;
//         for(int i:arr)
//         {
//             if(i>60)
//             count++;
//         }
//         return count;
//     }
// }
