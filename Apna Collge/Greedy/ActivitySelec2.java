import java.util.*;
public class ActivitySelec2 {
    public static void main(String[] args) {
        int start[] ={0,1,3,5,5,8};
        int end [] = {6,2,4,7,9,9};

        // here end time is not sorted so we need to sort it
        // so that we cn greedily select 1st activity
        int act[][] = new int[start.length][3];
        // 3 col for index,start,end
        for(int i=0;i<start.length;i++){
            act[i][0]=i; // index 
            act[i][1]=start[i];
            act[i][2]=end[i];
        }

        Arrays.sort(act,(a,b)-> Integer.compare(a[1], b[1]));
        // now little change
        int maxAct = 1;
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(act[0][0]); // added 1st idx
        int endTIme= act[0][2];
        for(int i=1;i<end.length;i++){
            if(act[i][1]>=endTIme){
                maxAct++;
                ans.add(act[i][0]);
                endTIme=act[i][2]; // update
            }
        }
    }
}
