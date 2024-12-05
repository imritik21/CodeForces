import java.util.*;
public class kthLevel {
    static class Node{
        int data;
        Node left,right;

        public Node(int data){
            this.data=data;
            this.left=null;
            this.right=null;
        }
    }
    static void printKLevel(Node root,int level,int k){
        if(root==null){
            return;
        }
        if(level==k){
            System.out.print(root.data+" ");
            return;
        }
        printKLevel(root.left, level+1, k);
        printKLevel(root.right, level+1, k);
    }
    static void helper(Node node,int data,int level){
        if(node==null){
            return;
        }
        if(node.data==data){
            System.out.println(level);
            return;
        }
        helper(node.left,data,level+1);
        helper(node.right,data,level+1);
    }
    // int getKLevel(Node root,int data){

    // }
    public static void main(String[] args) {
        /*
         *           1
         *         /   \
         *        2     3
         *       / \   / \
         *      4   5 6   7
         */
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        int k=3;
        printKLevel(root,1,k);
        // helper(root, 5, 1);
    }
}
