import java.util.Queue;
import java.util.Stack;
import java.util.concurrent.ConcurrentLinkedQueue;

/**
 * queue
 */
public class queue {

    public static void main(String[] args) {
        Queue<Integer> q = new ConcurrentLinkedQueue<>();
        q.add(1);
        q.add(2);
        q.add(3);
        q.remove();
        q.add(1);
        System.out.println(q);
        Stack<Integer> st = new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.pop();
        st.push(3);
        System.out.println(st);
        
    }
}