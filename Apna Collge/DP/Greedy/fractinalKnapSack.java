import java.util.*;

public class fractinalKnapSack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int val [] = {1,2,3};
        int weight[] = {3,2,1};
        int w = 4;

        double ratio [][] = new double[val.length][2];
        for(int i=0;i<val.length;i++){
            ratio[i][0]=i;
            ratio[i][1]=val[i]/(double)weight[i];
        }
        // sort the ration 
        Arrays.sort(ratio,Comparator.comparingDouble(o -> o[1]));

        // we want in dec order so traverse oppo
        // kyuki ratio jiska sbse jyada whi jyada profit dega
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
