import java.util.*;
public class kthAncestor {
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
    static Node LCA(Node root,int n1,int n2){
        // cond 1
        if(root == null || root.data==n1 || root.data == n2){
            return root;
        }
        // find left and right lca
        Node leftLca = LCA(root.left, n1, n2);
        Node rightLca = LCA(root.right, n1, n2);
        // now when they're null
        if(leftLca==null) return rightLca;
        if(rightLca==null) return leftLca;
        // else both are not null means root is ans 
        return root;
    }
    static Node lca(Node root,int n1,int n2){
        if(root==null || root.data==n1||root.data==n2){
            return root;
        }
        Node leftlca = lca(root.left,n1,n2);
        Node rightlca = lca(root.right,n1,n2);
        if(leftlca==null) return rightlca;
        if(rightlca==null) return leftlca;
        return root;
    }
    static int lcaDist(Node root,int n){
        if(root==null){
            return -1;// base case
        }
        if(root.data==n){
            return 0 ; // reached that  node
        }
        int lDist = lcaDist(root.left, n);
        int rDist = lcaDist(root.right, n);

        if(lDist==-1 && rDist==-1){
            return -1; // node does not exist
        }
        else if(lDist==-1) return rDist+1; // bcz we're on upper node
        else return lDist+1;
    }
    static int lcadist(Node root,int n){
        if(root==null) return -1;
        if(root.data==n) return 0;
        int ldist = lcadist(root.left, n);
        int rdist = lcadist(root.right, n);

        if(ldist==-1 && rdist==-1){
            return -1;
        }
        else if(ldist==-1) return rdist+1;
        else ldist+1;
    }
    static int minDist(Node root,int n1,int n2){
        Node lca = LCA(root, n1, n2);
        // find lca and then dist from them
        int dist1 = lcaDist(root,n1);
        int dist2 = lcaDist(root,n2);

        return dist1+dist2;
    }
    static int kthAncestor(Node root,int n,int k){
        // base case 
        if(root==null){
            return -1;
        }
        if(root.data==n){
            return 0;
        }
        int lDist = kthAncestor(root.left, n, k);
        int rDist = kthAncestor(root.right, n, k);

        if(lDist==-1 && rDist==-1){
            return -1;
        }
        int max = Math.max(lDist, rDist);
        if(max+1==k){
            System.out.print(root.data);
        }
        // wrna 
        return max+1;
    }
    
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
        // printKLevel(root,1,k);
        // System.out.println(LCA(root, 4, 5).data);
        // System.out.println(minDist(root, 4, 6));
        // System.out.println("kth ancestor "+kthAncestor(root, 2, 1));
        kthAncestor(root, 5, 1); // 2
    }
}
