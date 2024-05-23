import java.util.*;

public class DuplicateParenthesis {

    public static boolean containDuplicate(String str){
        int n = str.length();
        Stack<Character> st = new Stack<>();
        for(int i=0;i<n;i++){
            char ch = str.charAt(i);
            if(ch==')'){
                int cnt=0;
                while(st.peek()!='(' ){
                    st.pop();
                    cnt++;
                }
                if(cnt<1) return true;// contains duplicate
                else st.pop(); // opening pair popped
            }
            else{
                st.push(ch);
            }
        }
        return false; // no duplicates found
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        str = sc.nextLine();
        System.out.println(containDuplicate(str));
    }    
}
