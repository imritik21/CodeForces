import java.util.*;

public class reverseAstack {
    public static void pushBottom(Stack<Integer> s,int data){
        // base case when we empty the stack we'll push the data
        if(s.empty()){
            s.push(data);
            return;
        }
        // go and pop all
        int top = s.pop();
        pushBottom(s, data);
        // now add
        s.push(top);
    }
    public static void reverseStack(Stack<Integer> st){
        // base case when stack is empty
        if(st.isEmpty()){
            return;
        }
        int top = st.pop();
        reverseStack(st);
        // wapas aate hue bottom pe push
        pushBottom(st, top);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> s = new Stack<>();
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            int data = sc.nextInt();
            s.push(data);
        }
        System.out.println(s);
        reverseStack(s);
        System.out.println(s);
    }    
}
