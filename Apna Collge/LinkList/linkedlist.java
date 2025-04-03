import org.w3c.dom.Node;

import implementation.stack;

public class linkedlist {
    public static class Node{
        int data;
        Node next;

        // constructor
        public Node(int data){
            this.data=data;
            this.next=null;
        }
    }

    public static Node head;
    public static Node tail;
    public static int size;

    public void addFirst(int data){
        Node newNode = new Node(data);
        size++;
        if(head==null){
            head=tail=newNode;
            return;
        }
        newNode.next=head;
        head=newNode;
    }

    public void addLast(int data){
        Node lastNode = new Node(data);
        size++;
        if(head==null){
            head=tail=lastNode;
        }
        tail.next=lastNode;
        tail=lastNode;
    }
    public static void display(){
        Node temp = head;
        while(temp!=null){
            System.out.print(temp.data+"->");
            temp=temp.next;
        }
        System.out.println("null");
    }
    public static void add(int index,int data){
        Node newNode = new Node(data);
        size++;
        int i=0;
        Node temp=head;
        while(i<index-1){
            temp=temp.next;
            i++;
        }
        newNode.next=temp.next;
        temp=newNode;
    }

    public static int removeFirst(){
        if(size==0){
            System.out.println("empty");
            return Integer.MAX_VALUE;
        }
        else if(size==1){
            int val=head.data;
            head=tail=null;
            size=0;
            return val;
        }
        else{
            int val = head.data;
            head=head.next;
            size--;
            return val;
        }
    }

    public static int removeLast(){
        if(size==0){
            System.out.println("empty");
            return Integer.MAX_VALUE;
        }
        else if(size==1){
            int val = head.data;
            head=tail=null;
            size=0;
            return val;
        }
        else{
            Node temp=head;
            for(int i=0;i<size-2;i++){
                temp=temp.next;
            }
            int val = temp.next.data;
            temp.next=null;
            size--;
            return val;
        }
    }

    public static void Lsearch(int key){
        Node temp = head;
        int i=0;
        while(temp!=null){
            if(temp.data==key){
                System.out.println("found at inmdex"+i);
                return;
            }
            temp=temp.next;
            i++;
        }
        System.out.println("Not found");
    }
    public static void reverse(){
        Node curr = head;
        Node prev = null;
        Node newNode = null;
        while(curr!=null){
            newNode = curr.next;
            curr.next = prev;
            prev=curr;
            curr=newNode;
        }
        head=tail;
    }
    public Node getMid(Node head){
        Node slow = head;
        Node fast = head;
        while(fast.next!= null && fast.next.next != null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }

    public boolean checkPalindrome(){
        // step 1 find mid
        if(head==null || head.next==null){
            return true;
        }
        Node midNode = getMid(head);
        // step 2 reverse 2nd half
        Node prev = null;
        Node curr = midNode;
        Node nextNode = null;
        while(curr!=null){
            nextNode=curr.next;
            curr.next=prev;
            prev=curr;
            curr=nextNode;
        }
        Node right = prev;// right head
        Node left = head;

        while(right!=null){
            if(left.data!=right.data)return false;
            left=left.next;
            right=right.next;
        }
        return true;
    }
    public Node merge(Node head1,Node head2){
        Node mergeLL = new Node(-1);
        Node dummy = mergeLL;
        while(head1!=null && head2!=null){
            if(head1.data<=head2.data){
                dummy.next=head1;
                head1=head1.next;
                dummy=dummy.next;
            }
            else{
                dummy.next=head2;
                head2=head2.next;
                dummy=dummy.next;
            }
        }
        while(head1!=null){
            dummy.next=head1;
            head1=head1.next;
            dummy=dummy.next;
        }
        while(head2!=null){
            dummy.next=head2;
            head2=head2.next;
            dummy=dummy.next;
        }

        return mergeLL.next;
    }
    public Node mergeSort(Node head){
        if(head==null || head.next== null){
            return head;
        }
        Node mid = getMid(head);
        Node rightHead =  mid.next;
        mid.next=null;
        Node newLeft = mergeSort(head);
        Node newRight = mergeSort(rightHead);

        return merge(newLeft,newRight);
    }
    public static void main(String[] args) {
        linklist ll = new linklist();

        // ll.addFirst(1);
        // ll.addFirst(2);
        // ll.addFirst(3);
        // ll.addLast(2);
        // ll.addLast(5);
        // ll.add(3, 1);
        // ll.removeFirst();
        // ll.removeLast();
        // display();

        // System.out.println(size);
        // Lsearch(10);
        // Rsearch(head, 0, 69);
        // Rsearch(head, 0, 2);
        // Reverse();
        // display();
        // System.out.println(ll.checkPalindrome());
        ll.addFirst(1);
        ll.addFirst(0);
        ll.addFirst(2);
        ll.addFirst(1);
        ll.addFirst(0);
        ll.addFirst(2);
        display();
        ll.head=ll.mergeSort(head);
        display();
        // TC- O(nlogn)
    }
}
