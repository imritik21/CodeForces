import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class p2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[][] arr = new int[n][n];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    arr[i][j] = sc.nextInt();
                }
            }           
            List<String> al = new ArrayList<>();
             
            for(int i = 0; i < n; i+=k){
                String str = "";
                for(int j = 0; j < n; j+=k){
                    if(arr[i][j] == 0)
                        str = str+"0";  
                    else
                        str = str+"1";               
                }
                al.add(str);
            }
            for(int i = 0; i < al.size(); i++){
                System.out.println(al.get(i));
            } 
            
        }
    }
}