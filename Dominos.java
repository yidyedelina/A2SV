import java.util.Scanner;

public class Dominos {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int first = scan.nextInt();
        int second = scan.nextInt();
        int factor = (first * second) / 2;
        System.out.println(factor);
    }
}
