class Solution {
    public double averageWaitingTime(int[][] customers) {
        // double cur=0;
        // double total=0;
        // for(int []arr:customers){
        //     // specify order taking time if any order all order completed
        //     if(arr[0]>cur){
        //         cur=arr[0];
        //     }
        //     // initialize time when customer place order
        //     double takeOrder=arr[0];
        //     // when chef can deliver the food
        //     double deliver=cur+arr[1];
        //     // storing previous delivery time when chef can take new order
        //     cur+=arr[1];
        //     // store total time for avg calculation
        //     total+=(deliver-takeOrder);
        // }
        
        // return total/customers.length;
        double currentTime = 0;
        double totalWaitingTime = 0;
        for(int i=0;i<customers.length;i++){
            double arrivalTime  = customers[i][0];
            double prepTime = customers[i][1];
            if(currentTime < arrivalTime){
                currentTime = arrivalTime;
            }
            double waitingTime = currentTime + prepTime;
            currentTime += prepTime;
            totalWaitingTime += (waitingTime - arrivalTime); 
        }
        return totalWaitingTime/customers.length;
    }
}
