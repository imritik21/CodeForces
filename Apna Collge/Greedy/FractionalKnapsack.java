import java.util.*;

public class FractionalKnapsack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int val [] = {60,100,120};
        int weight[] = {10,20,30};
        int w = 50;

        double ratio [][] = new double[val.length][2];
        for(int i=0;i<val.length;i++){
            ratio[i][0]=i;
            ratio[i][1]=val[i]/(double)weight[i];
        }
        // sort the ration 
        Arrays.sort(ratio,Comparator.comparingDouble(o -> o[1]));

        // we want in dec order so traverse oppo
        int capacity = w;
        int finalVal = 0;
        for(int i= ratio.length-1;i>=0;i--){
            int idx = (int)ratio[i][0];

            if(capacity>= weight[idx]){
                finalVal+=val[idx];
                capacity-=weight[idx];
            }
            else{
                // want in fraction
                finalVal+=(ratio[i][1]*capacity);
                capacity=0;
                break; // bag is full
            }
        }
        System.out.println(finalVal);
    }    
}
