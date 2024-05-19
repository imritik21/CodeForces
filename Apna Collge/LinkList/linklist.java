import org.w3c.dom.Node;

public class linklist {
    public static class Node{
        int data;
        Node next;

        //constructor
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
        Node ptr = head;
        while(ptr != null){
            System.out.print(ptr.data+"->");
            ptr=ptr.next;
        }
        System.out.println("null");
    }
    public static void add(int index,int data){
        Node newNode = new Node(data);
        size++;
        Node temp = head;
        int i=0;
        while(i<index-1){
            temp=temp.next;
            i++;
        }
        newNode.next=temp.next;
        temp.next=newNode;
    }
    public static int removeFirst(){
        if(size==0){
            System.out.println("Linklist is empty");
            return Integer.MAX_VALUE;
        }
        else if(size==1){
            int val=head.data;
            head=tail=null;
            size=0;
            return val;
        }
        int val=head.data;
        head=head.next;
        size--;
        return val;
    }
    public static int removeLast(){
        if(size==0){
            System.out.println("Empty LL");
            return Integer.MAX_VALUE;
        }
        else if(size==1){
            int val = head.data;
            head=tail=null;
            size=0;
            return val;
        }
        else{
            Node prev = head;
            for(int i=0;i<size-2;i++){
                prev=prev.next;
            }
            // reached
            int val=prev.next.data;
            prev.next=null;
            tail=prev;
            size--;
            return val;
        }

    }
    public static void Lsearch(int key){
        Node ptr = head;
        int i=0;
        while(ptr!=null){
            if(ptr.data==key){
                System.out.println("Key found at index "+i);
                return;
            }
            ptr=ptr.next;
            i++;
        }
        System.out.println("Key Doesn't exist! ");
    }
    public static void Rsearch(Node head,int ind,int key){
        if(ind==size || head==null){
            System.out.println("Key doesn't exist");
            return;
        }
        if(head.data==key){
            System.out.println("key found at index "+ind);
            return;
        }
        Rsearch(head.next, ind+1, key);
    }
    public static void Reverse(){
        Node curr=head;
        Node prev=null;
        Node newNode=null;
        while(curr != null){
            newNode=curr.next;
            curr.next=prev;
            prev=curr;
            curr=newNode;
        }
        head=tail;
    }
    public void nthNodeFromEnd(int n){
        int sz=0;
        Node temp=head;
        while(temp != null){
            temp=temp.next;
            sz++;
        }
        if(n==sz){
            head=head.next; // remove first
            return;
        }
        int i=1;
        int iTofind = sz-n; // from start
        Node prev=head;
        while(i<iTofind){
            prev=prev.next;
            i++;
        }
        prev.next=prev.next.next;
        return;
    }
    public static Node getMiddle(Node head)
    {
        // Your code here
        if(head == null){
            return null;
        }
        else if(head.next==null){
            return head;
        }
        else{
            Node slow=head;
            Node fast=head;
            while(fast!= null && fast.next !=null){
                
                fast=fast.next;
                if(fast.next != null){
                    fast=fast.next;
                }
                slow=slow.next;
            }
            return slow;
        }
    }
    public boolean checkPalindrome(){
        // step 1 - find mid
        // step 3 - comp
        if(head==null || head.next==null){
            return true;
        }

        Node midNode=getMiddle(head);
        // step 2 - reverse 2nd half
        Node prev=null;
        Node curr=midNode;
        Node next;
        while(curr != null){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        Node right = prev;// right head;
        Node left=head;

        while(right != null){
            if(left.data!=right.data){
                return false;
            }
            left=left.next;
            right=right.next;
        }
        return true;
    }
    public static void main(String[] args) {
        linklist ll = new linklist();
        
        ll.addFirst(1);
        ll.addFirst(2);
        ll.addFirst(3);
        ll.addLast(2);
        ll.addLast(5);
        ll.add(3,1);
        ll.removeFirst();
        ll.removeLast();
        display();

        System.out.println(size);
        Lsearch(10);
        Rsearch(head,0,69);
        Rsearch(head,0,2);
        Reverse();
        display();
        System.out.println(ll.checkPalindrome());
    }
}