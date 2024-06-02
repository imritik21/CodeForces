import java.util.*;
public class topView {
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
    static class Info{
        int hzD;
        Node node;

        public Info(Node node , int hzD){
            this.hzD=hzD;
            this.node=node;
        }
    }
    public static void topView(Node node){
        // level order
        Queue<Info> q = new LinkedList<>();
        HashMap<Integer,Node> map = new HashMap<>();
        q.add(new Info(node, 0));
        q.add(null);
        int min=0,max=0;
        while(!q.isEmpty()){
            Info curr = q.remove();
            if(curr == null){
                if(q.isEmpty()){
                    break;
                }
                else{
                    q.add(null);
                }
            }
            else{
                if(!map.containsKey(curr.hzD)){
                    // 1st occurance so push
                    map.put(curr.hzD, curr.node);
                }
                if(curr.node.left!=null){
                    q.add(new Info(curr.node.left, curr.hzD-1));
                    min=Math.min(min, curr.hzD-1);
                }
                if(curr.node.right!=null){
                    q.add(new Info(curr.node.right, curr.hzD+1));
                    max=Math.max(max, curr.hzD+1);
                }
            }
        }
        for(int i=min;i<=max;i++){
            System.out.print(map.get(i).data+" ");
        }
        System.out.println();
    }
    public static void bottomView(Node node){
        // level order
        Queue<Info> q = new LinkedList<>();
        HashMap<Integer,Node> map = new HashMap<>();
        q.add(new Info(node, 0));
        // q.add(null);
        int min=0,max=0;
        while(!q.isEmpty()){
            Info curr = q.remove();
            // if(curr == null){
            //     if(q.isEmpty()){
            //         break;
            //     }
            //     else{
            //         q.add(null);
            //     }
            // }
            // else{
                
                    // update everytime
                    map.put(curr.hzD, curr.node);
                if(curr.node.left!=null){
                    q.add(new Info(curr.node.left, curr.hzD-1));
                    min=Math.min(min, curr.hzD-1);
                }
                if(curr.node.right!=null){
                    q.add(new Info(curr.node.right, curr.hzD+1));
                    max=Math.max(max, curr.hzD+1);
                }
            // }
        }
        for(int i=min;i<=max;i++){
            System.out.print(map.get(i).data+" ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        /*
         *              1
         *            /   \
         *           2     3
         *          / \   / \
         *         4   5 6   7
         */
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        topView(root);
        bottomView(root);
    }
}
