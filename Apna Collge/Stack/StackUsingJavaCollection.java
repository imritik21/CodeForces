import java.util.*;

public class StackUsingJavaCollection {

    public static void increment(int k,int val,Stack<Integer> s){
        while(k > 0){
            int topp = s.firstElement();
            topp+=val;
            s.push(topp);
            k--;
        }
    }
    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        s.push(1);
        s.push(2);
        s.push(3);

        while(!s.empty()){
            System.out.println(s.peek());
            s.pop();
        }

        increment(3,100,s);
        System.out.println(s);
    }    
}
