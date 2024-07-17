import java.util.*;

public class number1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        ArrayList<Integer> a1 = new ArrayList<>();
        ArrayList<Integer> b1 = new ArrayList<>();
        ArrayList<Integer> c1 = new ArrayList<>(Collections.nCopies(n, 0)); 

        for (int i = 0; i < n; i++) {
            a1.add(sc.nextInt()); 
        }
        for (int i = 0; i < n; i++) {
            b1.add(sc.nextInt()); 
            c1.set(a1.get(i) - 1, b1.get(i)); 
        }
        for (int i = 0; i < n; i++) {
            System.out.print(c1.get(i) + " "); 
        }
        System.out.println();
    }
}
