package Water_Bottles;

public class Water_Bottles {
    public static int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;
        int DrankBottles = numBottles;
        while(count>=numExchange){
            int quotient = count/numExchange;
            DrankBottles += quotient;
            count = count%numExchange+quotient;
        }
        return DrankBottles;
    }

    public static void main(String[] args) {
        int numBottles = 9;
        int numExchange = 3;
        System.out.println("Maximum bottles drank: " + numWaterBottles(numBottles, numExchange)); // Output: 13
    }
}
