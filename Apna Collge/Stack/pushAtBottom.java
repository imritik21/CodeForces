import java.util.*;

public class pushAtBottom {
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
    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        s.push(1);
        s.push(2);
        s.push(3);
        System.out.println(s);
        pushBottom(s, 4);
        System.out.println(s);
    }
}
