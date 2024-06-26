import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BTtoBST {

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

    // Step 3: Perform an inorder traversal and replace the values with sorted values
    public static void arrayToBST(Node node, List<Integer> inorder, int[] index) {
        if (node == null) {
            return;
        }
        arrayToBST(node.left, inorder, index);
        node.data = inorder.get(index[0]++);
        arrayToBST(node.right, inorder, index);
    }

    // Convert binary tree to BST
    public static Node binaryTreeToBST(Node root) {
        if (root == null) {
            return null;
        }

        // Store inorder traversal of the tree in a list
        List<Integer> inorder = new ArrayList<>();
        storeInorder(root, inorder);

        // Sort the list
        Collections.sort(inorder);

        // Replace values of the original tree with the sorted values
        int[] index = {0}; // Use an array to keep track of the current index
        arrayToBST(root, inorder, index);

        return root;
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

    // Main function to test the conversion
    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(30);
        root.right = new Node(15);
        root.left.left = new Node(20);
        root.right.right = new Node(5);

        System.out.println("Inorder traversal of the original binary tree:");
        printInorder(root);
        System.out.println();

        root = binaryTreeToBST(root);

        System.out.println("Inorder traversal of the converted BST:");
        printInorder(root);
        System.out.println();
    }
}
