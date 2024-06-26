import java.util.ArrayList;
import java.util.List;

public class BalanceBST {

    // Node class definition
    public static class Node {
        int data;
        Node left, right;

        public Node(int item) {
            data = item;
            left = right = null;
        }
    }

    // Step 1: Perform an inorder traversal and store the elements in a list
    public static void storeInorder(Node node, List<Integer> inorder) {
        if (node == null) {
            return;
        }
        storeInorder(node.left, inorder);
        inorder.add(node.data);
        storeInorder(node.right, inorder);
    }

    // Step 2: Construct a balanced BST from the sorted list
    public static Node sortedListToBST(List<Integer> inorder, int start, int end) {
        if (start > end) {
            return null;
        }

        // Get the middle element and make it the root
        int mid = (start + end) / 2;
        Node node = new Node(inorder.get(mid));

        // Recursively construct the left and right subtrees
        node.left = sortedListToBST(inorder, start, mid - 1);
        node.right = sortedListToBST(inorder, mid + 1, end);

        return node;
    }

    // Function to balance the BST
    public static Node balanceBST(Node root) {
        if (root == null) {
            return null;
        }

        // Store inorder traversal of the tree in a list
        List<Integer> inorder = new ArrayList<>();
        storeInorder(root, inorder);

        // Construct a balanced BST from the sorted list
        return sortedListToBST(inorder, 0, inorder.size() - 1);
    }

    // Helper function to print the inorder traversal of the tree
    public static void printInorder(Node node) {
        if (node == null) {
            return;
        }
        printInorder(node.left);
        System.out.print(node.data + " ");
        printInorder(node.right);
    }

    // Main function to test the balancing
    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(5);
        root.right = new Node(20);
        root.left.left = new Node(3);
        root.left.right = new Node(7);
        root.right.left = new Node(15);
        root.right.right = new Node(25);

        System.out.println("Inorder traversal of the original BST:");
        printInorder(root);
        System.out.println();

        root = balanceBST(root);

        System.out.println("Inorder traversal of the balanced BST:");
        printInorder(root);
        System.out.println();
    }
}
