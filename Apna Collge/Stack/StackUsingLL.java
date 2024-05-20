import java.util.*;

public class StackUsingLL {
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }
    static class Stack{
        static Node head = null; // initially
        // methods
        public static boolean isEmpty(){
            return head==null;
        }
        // push
        // push actually means that our new head will shift everytime a new ele is added
        public static void push(int data){
            Node newNode = new Node(data);
            if(isEmpty()){
                // means newNode is only our head
                head=newNode;
                return;
            }
            // else
            newNode.next=head; //  added newNode to LL
            head=newNode; // assigned head to it
        }
        // pop
        public static int pop(){
            if(isEmpty()){
                return -1;
            }
            int top = head.data;
            head=head.next;
            return top;
        }
        // peeek
        public static int peek(){
            if(isEmpty()){
                return -1;
            }
            return head.data;
        }
    }
    public static void main(String[] args) {
        // Stack<Integer> s = new Stack<>();
        Stack s = new Stack();
        s.push(1);
        s.push(2);
        s.push(3);

        while(!s.isEmpty()){
            System.out.println(s.peek());
            s.pop();
        }
    }
}
