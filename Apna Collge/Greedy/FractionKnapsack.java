
public class FractionKnapsack {
    class Item {
        int value, weight;
        Item(int x, int y){
            this.value = x;
            this.weight = y;
        }
    }
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        // sort the obj according to value
        double ratio [][] = new double[arr.length][2];
        
        for(int i=0;i<arr.length;i++){
            ratio[i][0]=i;
            ratio[i][1]=(double)arr[i].value/arr[i].weight;
        }
        
        Arrays.sort(ratio,Comparator.comparingDouble(o->o[1]));
        double finalVal=0;
        int capacity=w;
        for(int i=ratio.length-1;i>=0;i--){
            int idx = (int)ratio[i][0];
            if(capacity>=arr[idx].weight){
                finalVal+=arr[idx].value;
                capacity-=arr[idx].weight;
            }
            else{
                // take the ratio instead
                finalVal+=(ratio[i][1]*capacity);
                capacity=0;
                break;
            }
        }
        return finalVal;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String inputLine[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int w = Integer.parseInt(inputLine[1]);
            Item[] arr = new Item[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0, k = 0; i < n; i++) {
                arr[i] = new Item(Integer.parseInt(inputLine[k++]),
                                  Integer.parseInt(inputLine[k++]));
            }
            System.out.println(
                String.format("%.6f", new Solution().fractionalKnapsack(w, arr, n)));
        }
    }
}
