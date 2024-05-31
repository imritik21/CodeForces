import java.util.*;
public class Trees {
    public static class Node{
        int data;
        Node left;
        Node right;

        public Node(int data){
            this.data=data;
            this.left=null;
            this.right=null;
        }
    }
    public static void preorder(Node root){
        if(root == null){
            return;
        }
        System.out.print(root.data+" ");
        preorder(root.left);
        preorder(root.right);
    }
    public static boolean isIdentical(Node node,Node subroot){
        if(node == null && subroot==null){
            return true;
        }
        else if(node==null || subroot==null || node.data!= subroot.data){
            return false;
        }
        // check in left and right node
        if(!isIdentical(node.left, subroot.left)) return false;
        if(!isIdentical(node.right, subroot.right)) return false;

        // no false is true
        return true;
    }
    public static boolean isSubtree(Node root,Node subroot){
        if(root == null){ // base case
            return false; // subroot not found
        }
        if(root.data == subroot.data){ // agar data same hote hai
            if(isIdentical(root,subroot)){
                return true;
            }
        }
        // else data same nhi mila to search kro left and right me
        // left subtree me find and right subtree
        // boolean leftans = isSubtree(root.left, subroot);
        // boolean rightans = isSubtree(root.right, subroot);

        return isSubtree(root.left, subroot) || isSubtree(root.right, subroot);
    }
    public static void main(String[] args) {
        /*
                   1
                  / \
                 2   3
                / \  /\
               4   5 6 7
         * 
         */
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        /*
         *         2
         *        / \
         *       4   5
         */
        Node subRoot = new Node(2);
        subRoot.left = new Node(4);
        subRoot.right = new Node(5);

        System.out.println(isSubtree(root, subRoot));
    }
}
