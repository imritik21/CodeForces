import java.util.*;
public class MaxLenOfChain {
    public static void main(String[] args) {
        int pairs [][] = {{5,24},{39,60},{5,28},{27,40},{50,30}};
        // now sort it acc to 2nd col
        Arrays.sort(pairs,Comparator.comparingDouble(o->o[1]));

        int chainLen=1; // initially took 1st GREEDY
        int chainEnd = pairs[0][1];
        // now loop from 1 to n
        for(int i=1;i<pairs.length;i++){
            if(pairs[i][0]>chainEnd){ // 1st chain is already selected
                chainLen++;
                chainEnd=pairs[i][1]; // update end
            }
        }
        System.out.println("Max len is "+chainLen);
    }
}
