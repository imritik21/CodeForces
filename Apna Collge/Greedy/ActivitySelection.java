import java.util.*;

public class ActivitySelection {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int start [] = new int[n];
        int end [] = new int[n];
        for(int i=0;i<n;i++){
            start[i]=sc.nextInt();
        }

        for(int i=0;i<n;i++){
            end[i]=sc.nextInt();
        }

        int maxAct=0;
        ArrayList<Integer> ans = new ArrayList<>();
        // as end time is sorted we choose our 1st activity as 1st
        maxAct=1; // setting maxAct as 1 initially as we choose 
        ans.add(0); // added index of 1st activity
        int endTime= end[0];
        // now rest 
        for(int i=1;i<end.length;i++){
            if(start[i]>=endTime){
                maxAct++;
                ans.add(i);
                endTime=end[i];
            }
        }

        // now print
        System.out.println("Max activies : "+maxAct);
        for(int i=0;i<ans.size();i++){
            System.out.print("A"+ans.get(i)+" ");
        }
    }    
}