import java.util.*;

import linklist.Node;

public class LL {

    public void mergeSort(){
        if(head==null && head.next == null);
        // find mid
        Node mid = getMid();
        // left and right MS
        Node rightHead=mid.next;
        mid.next = null;
        Node newLeft = mergeSort();
        Node newRight= mergeSort();

        // merge
        return merge(newLeft,newRight)
    }
    public static void main(String[] args) {
        LinkedList ll = new LinkedList<>();
        ll.addFirst(1);
        ll.addLast(2);
        ll.addFirst(0);
        ll.removeLast();
        ll.removeFirst();
        System.out.println(ll);
    }
}
