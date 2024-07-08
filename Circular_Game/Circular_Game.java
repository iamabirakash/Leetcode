import java.util.ArrayList;

public class Circular_Game {
    public static int circulargame(int n, int k){
        ArrayList<Integer> players = new ArrayList<Integer> ();
        for(int i = 1; i <= n; i++){
            players.add(i);
        }
        int ball = -1;
        while(players.size() > 1){
            ball = (ball + k) % players.size();
            players.remove(ball);
            ball--;
        }
        return (int)players.get(0);
    }

    public static void main(String[] args) {
        int n = 5; // Number of people in the game
        int k = 2; // Eliminate every k-th person
        System.out.println("The winner is: " + circulargame(n, k));
    }
}
