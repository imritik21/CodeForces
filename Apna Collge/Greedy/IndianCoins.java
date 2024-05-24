import java.util.*;
public class IndianCoins {
    public static void main(String[] args) {
        Integer coins [] = {186,419,83,408}; 
        int amount = 6249;
        /// reverse sort
        Arrays.sort(coins,Comparator.reverseOrder());

        int ans=0;
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0;i<coins.length;i++){
            if(coins[i]<= amount){
                while(coins[i]<=amount){
                    ans++;
                    list.add(coins[i]);
                    amount-=coins[i];
                }
            }
        }
        System.out.println("Coins/change req "+ans);

        for(int i=0;i<list.size();i++){
            System.out.print(list.get(i)+" ");
        }
        System.out.println();
    }
}
