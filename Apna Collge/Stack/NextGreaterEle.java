import java.util.*;

public class NextGreaterEle {

    public static void main(String[] args) {
        int arr []= {6,8,0,1,3};
        int nextGreater [] =new int[arr.length];
        Stack<Integer> st=new Stack<>();
        for(int i=arr.length-1;i>=0;i--){
            while(!st.isEmpty() && arr[st.peek()]<=arr[i]){
                st.pop();
            }

            if(st.isEmpty()){
                nextGreater[i]=-1;
            }
            else{
                nextGreater[i]=arr[st.peek()];
            }
            st.push(i);
        }

        for(int i=0;i<nextGreater.length;i++){
            System.out.print(nextGreater[i]+" ");
        }
    }
}