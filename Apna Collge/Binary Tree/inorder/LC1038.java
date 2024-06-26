import java.util.*;
public class LC1038 {
    public static int prev=0;
    static class Node{
        int data;
        Node left;
        Node right;

        public Node(int data){
            this.data=data;
            this.left=null;
            this.right=null;
        }
    }
    
    public static void inorder(Node root){
        if(root==null) return;
        inorder(root.right);
        prev = prev + root.data; 
        System.out.print(prev+" ");
        inorder(root.left);
    }
    public static void main(String[] args) {
        Node root = new Node(4);
        root.left= new Node(1);
        root.right=new Node(6);

        root.left.left=new Node(0);
        root.left.right=new Node(2);
        root.left.right.right=new Node(3);

        root.right.left=new Node(5);
        root.right.right=new Node(7);
        root.right.right.right=new Node(8);

        inorder(root);
    }
}
