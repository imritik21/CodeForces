import java.util.*;

public class LongestValidSubstr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        
        Stack<Integer> st = new Stack<>();
        st.push(-1);
        int maxLen=0;
        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);

            if(ch=='(') st.push(i);
            else{
                st.pop();
                if(st.isEmpty()) st.push(i);
                maxLen=Math.max(maxLen,i-st.peek());
            }
        }
        System.out.println(maxLen);
    }
}


