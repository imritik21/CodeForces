
public class fib {
    public static int fibb(int n,int dp[]){
        if(n==0 || n== 1){
            return n;
        }
        if(dp[n] != 0){
            // already fib(n) is calculated
            return dp[n];
        }
        // else calc
        dp[n] = fibb(n-1,dp)+fibb(n-2,dp);
        return dp[n]; // final ans
    }
    public static void main(String[] args) {
        int n=5;
        int dp[] = new int[n+1];
        System.out.println(fibb(n,dp));
    }
}
