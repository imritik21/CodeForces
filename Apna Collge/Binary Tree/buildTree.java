import java.util.LinkedList;
import java.util.Queue;

public class buildTree {
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
    public static class BinaryTree{
        static int idx = -1;
        public static Node build(int nodes[]){
            idx++;
            if(nodes[idx]==-1){
                return null;
            }
            // create new node
            Node newNode = new Node(nodes[idx]);
            newNode.left = build(nodes);
            newNode.right = build(nodes);

            return newNode;
        }
        public static void preorder(Node root){
            if(root==null){
                // return;
                // System.out.print("-1 ");
                return;
            }
            System.out.print(root.data+" ");
            preorder(root.left);
            preorder(root.right);
        }
        public static void inorder(Node root){
            if(root==null){
                // return;
                // System.out.print("-1 ");
                return;
            }
            inorder(root.left);
            System.out.print(root.data+" ");
            inorder(root.right);
        }
        public static void postorder(Node root){
            if(root==null){
                // return;
                // System.out.print("-1 ");
                return;
            }
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.data+" ");
        }
        // level order traversal
        public static void levelOrder(Node root){
            if(root == null){
                return;
            }
            Queue<Node> q = new LinkedList<>();
            q.add(root);
            q.add(null);
            
            while(!q.isEmpty()){
                Node currNode = q.remove();
                if(currNode == null){
                    System.out.println();
                    if(q.isEmpty()){
                        return; // last pe pahuch gye
                    }
                    else{
                        q.add(null);
                    }
                }
                else{
                    // print krdo and uske left right child ko queue me add
                    System.out.print(currNode.data+" ");
                    if(currNode.left != null){
                        q.add(currNode.left);
                    }
                    if(currNode.right != null){
                        q.add(currNode.right);
                    }
                }
            }
        }
        public static void levelOrd(Node root){
            if(root==null) return;
            Queue<int> q = new LinkedList<>();

            q.add(root);
            q.add(null);
            while(!q.isEmpty()){
                Node currNode = q.remove();
                if(currNode==null){
                    if(q.isEmpty()){
                        return;
                    }
                    else{
                        q.add(null);
                    }
                }
                else{
                    System.out.println(currNode.data+" ");
                    if(currNode.left!=null){
                        q.add(currNode.left);
                    }
                    if(currNode.right!=null){
                        q.add(currNode.right);
                    }
                }
            }
        }
        public static int height(Node root){
            if(root==null){
                return 0;
            }
            int lh = height(root.left);
            int rh = height(root.right);
            return Math.max(lh, rh)+1;
        }
        public static int countNode(Node root){
            if(root == null) return 0;
            int leftCnt = countNode(root.left);
            int rightCnt = countNode(root.right);
            return leftCnt+rightCnt+1;
        }
        public static int sumOfNodes(Node root){
            if(root==null){
                return 0;
            }
            int leftSum = sumOfNodes(root.left);
            int righSum = sumOfNodes(root.right);
            return leftSum+righSum+root.data;
        }
        public static int diameter(Node root){
            if(root==null) return 0; // 0 as diameter
            // cal left and right diameter and self dia
            int leftdia= diameter(root.left);
            int rightdia= diameter(root.right);
            // now calc height of left and right half
            int lh = height(root.left);
            int rh = height(root.right);
            int selfdia = lh+rh+1;

            return Math.max(rightdia, Math.max(leftdia, selfdia));
        }
        static class Info{
            int diam;
            int ht;

            public Info(int diam,int ht){
                this.diam=diam;
                this.ht=ht;
            }
        }
        public static Info diameter2(Node root){
            if(root == null){
                return new Info(0,0);
            }
            Info leftInfo = diameter2(root.left);
            Info rightInfo = diameter2(root.right);

            int diam = Math.max(leftInfo.diam, Math.max(rightInfo.diam, leftInfo.ht+rightInfo.ht+1 ));
            int ht = Math.max(leftInfo.ht, rightInfo.ht)+1;

            return new Info(diam, ht);
        }
    }
    public static void main(String[] args) {
        int nodes[]= {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        /*
         *          1
         *         / \
         *        2   3
         *       / \   \
         *      4   5   6
         */
        BinaryTree tree = new BinaryTree();
        Node root = tree.build(nodes);
        System.out.println(root.data);
        tree.preorder(root);
        System.out.println();
        tree.inorder(root);
        System.out.println();
        tree.postorder(root);
        System.out.println();
        tree.levelOrder(root);
        System.out.println("height of tree is "+tree.height(root));
        System.out.println("Count of tree is "+tree.countNode(root));
        System.out.println("Sum of Nodes are "+tree.sumOfNodes(root));
        System.out.println("Diameter of tree is "+tree.diameter(root));
        System.out.println("Diameter of tree is "+tree.diameter2(root).diam);
    }
}
