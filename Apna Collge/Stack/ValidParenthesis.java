import java.util.*;

public class ValidParenthesis {

    public static boolean isValid(String str){
        Stack<Character> st = new Stack<>();
        for(int i=0;i<str.length();i++){
            char c = str.charAt(i);
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else{
                // closing case
                // )))))))) check khali to nhi opeinh h hi nhi
                if(st.isEmpty()) return false;

                // pair form ho rha hai
                if((st.peek()=='(' && c==')')|| (st.peek()=='[' && c==']') || (st.peek()=='{' && c=='}') ){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.isEmpty()) return true;
        else return false;
    }
    public static void main(String[] args) {
        String str = "(){}{}{}";
        System.out.println(isValid(str));
    }    
}
