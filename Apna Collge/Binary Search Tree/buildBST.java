import java.util.*;

public class buildBST {
    public static class Node{
        int data;
        Node left;
        Node right;

        public Node(int data){
            this.data = data;
        }
    }
    public static Node insert(Node root, int val){
        if(root == null){
            root = new Node(val);
            return root; // initially empty then create new and push new root 
        }
        if(root.data>val){
            // left subtree and store in root.left
            root.left = insert(root.left, val);
        }
        else{
            // right subtree and store in root.right
            root.right = insert(root.right, val);
        }
        // at llast return root
        return root;
    }
    public static void inorder(Node root){
        if(root == null){
            return;
        }
        inorder(root.left);
        System.out.print(root.data+" ");
        inorder(root.right);
    }
    public static boolean search(Node root,int key){
        if(root == null){
            return false;
        }
        if(root.data == key){
            return true;
        }
        if(root.data>key){
            return search(root.left, key);
        }
        else{
            return search(root.right, key);
        }
    }
    public static Node findInorderSucc(Node root){
        // in this case root won't be null
        while(root.left != null){
            root=root.left;
        }
        return root;
    }
    public static Node delete(Node root,int val){
        if(root == null){
            return null;
        }
        if(root.data>val){
            root.left = delete(root.left, val);
        }
        else if(root.data<val){
            root.right = delete(root.right, val);
        }
        else{
            // data found
            // case 1 if root is null
            if(root.left==null && root.right==null){
                return null ; // null will be returned 
            }
            // case 2 if it has single child
            if(root.left==null){
                return root.right; // return its child
            }
            else if(root.right==null){
                return root.left;
            }
            // case 3 
            Node IS = findInorderSucc(root.right); // inordersucc is leftmost ele of right
            root.data=IS.data;
            root.right = delete(root.right, val);
        }
        return root;
    }
    public static void printInRange(Node root,int k1,int k2){
        if(root==null){
            return;
        }
        if(root.data>=k1 && root.data<=k2){
            printInRange(root.left, k1, k2);
            System.out.print(root.data+" ");
            printInRange(root.right, k1, k2);
        }
        else if(root.data>k1){
            printInRange(root.left, k1, k2);
        }
        else{
            printInRange(root.right, k1, k2);
        }
    }
    public static void printPath(ArrayList<Integer> path){
        for(int i=0;i<path.size();i++){
            System.out.print(path.get(i)+" ");
        }
        System.out.println();
    }
    public static void printRoot2Leaf(Node root,ArrayList<Integer> path){
        // base case 
        if(root==null){
            return;
        }
        path.add(root.data);
        if(root.left==null && root.right==null){
            printPath(path);
            // return;
        }
        printRoot2Leaf(root.left, path);
        printRoot2Leaf(root.right, path);
        // backtrack
        path.remove(path.size()-1);
    }
    public static Node Mirror(Node root){
        if(root==null){
            return null;
        }
        Node leftSubtree = Mirror(root.left);
        Node rightSubtree = Mirror(root.right);
        // now swap them
        root.left=rightSubtree;
        root.right=leftSubtree;

        return root;
    }
    public static boolean isBst(Node root,Node min,Node max){
        if(root==null){
            return true;
        }
        if(min != null && root.data<=min.data) return false;
        if(max != null && root.data>= max.data) return false;
        return isBst(root.left, min, root)&& isBst(root.right, root, max);
    }
    public static void main(String[] args) {
        int values[] = {8,5,3,6,10,11,14};
        Node root = null;

        for(int i=0;i<values.length;i++){
            root = insert(root, values[i]);
        }

        inorder(root);
        // System.out.println(search(root, 6));
        System.out.println();
        // delete(root, 10);
        // inorder(root);
        // printInRange(root, 4, 6);
        // ArrayList<Integer> path = new ArrayList<>();
        // printRoot2Leaf(root, path);
        Mirror(root);
        inorder(root);
        System.out.println();
        System.out.println(isBst(root, null, null));

    }
}
