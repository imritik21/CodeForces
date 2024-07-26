public class build_Tree {
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
        public static Node built(int nodes[]){
            idx++;
            if(nodes[idx]==-1){
                return null;
            }
        }
    }
    public static void main(String[] args) {

    }
}
