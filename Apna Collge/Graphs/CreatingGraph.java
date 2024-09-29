import java.util.*;

class CreatingGraph {
    static class Edge {
        int src;
        int dest;
        int wt;

        public Edge(int src, int dest, int wt) {
            this.src = src;
            this.dest = dest;
            this.wt = wt;
        }
    }

    static void createGraph(ArrayList<Edge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        // 0 - vertex
        // graph[0].add(new Edge(0, 1, 1));
        // graph[0].add(new Edge(0, 2, 1));
        // // 1 - vertex
        // graph[1].add(new Edge(1, 0, 1));
        // graph[1].add(new Edge(1, 3, 1));
        // // 2 - vertex
        // graph[2].add(new Edge(2, 0, 1));
        // graph[2].add(new Edge(2, 4, 1));
        // // 3 - vertex
        // graph[3].add(new Edge(3, 1, 1));
        // graph[3].add(new Edge(3, 4, 1));
        // graph[3].add(new Edge(3, 5, 1));
        // // 4 - vertex
        // graph[4].add(new Edge(4, 2, 1));
        // graph[4].add(new Edge(4, 3, 1));
        // graph[4].add(new Edge(4, 5, 1));

        
        // graph[5].add(new Edge(5, 3, 1));
        // graph[5].add(new Edge(5, 4, 1));
        // graph[5].add(new Edge(5, 6, 1));

        // graph[6].add(new Edge(6, 5, 1));

        graph[0].add(new Edge(0, 1, 2));
        graph[0].add(new Edge(0, 2, 4));
        
        graph[1].add(new Edge(1, 3, 7));
        graph[1].add(new Edge(1, 2, 1));
        
        graph[2].add(new Edge(2, 4, 3));
        
        graph[3].add(new Edge(3, 5, 1));
        
        graph[4].add(new Edge(1, 3, 7));
        graph[4].add(new Edge(4, 5, 5));
    }

    // public static void bfs(ArrayList<Edge> graph[]){
    //     boolean vis[] = new boolean[graph.length];
    //     for(int i=0;i<graph.length;i++){
    //         if(!vis[i]){
    //             bfsHelper(graph, vis);
    //         }
    //     }
    // }
    public static void bfs(ArrayList<Edge> graph[]){
        boolean vis[] = new boolean[graph.length];
        // visit every node
        for(int i=0;i<graph.length;i++){
            if(!vis[i]){
                bfsHelper(graph, vis);
            }
        }
    }
    public static void bfsHelper(ArrayList<Edge> graph[],boolean vis[]){
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        while(!q.isEmpty()){
            int curr = q.remove();
            if(!vis[curr]){
                // visit kro
                System.out.print(curr+" ");
                vis[curr]=true;
                // saare neighbours ko visit kro iske
                for(int i=0;i<graph[curr].size();i++){
                    Edge e = graph[curr].get(i);
                    q.add(e.dest);
                }
            }
        }
    }
    // public static void bfsHelper(ArrayList<Edge> graph[],boolean vis[]){ // O(V+E)
    //     Queue<Integer> q = new LinkedList<>();
    //     // start from 0 src
    //     q.add(0); // src = 0;
    //     while(!q.isEmpty()){
    //         int curr = q.remove();

    //         if(!vis[curr]){
    //             // visit curr
    //             System.out.print(curr+" ");
    //             vis[curr]=true;
    //             // saare neighbours ko q me add
    //             for(int i=0;i<graph[curr].size();i++){
    //                 Edge e = graph[curr].get(i);
    //                 q.add(e.dest);
    //             }
    //         }
    //     }
    // }

    public static void dfs(ArrayList<Edge> graph[]){
        boolean vis[] = new boolean[graph.length];
        for(int i=0;i<graph.length;i++){
            if(!vis[i]){
                dfsHelper(graph,i,vis);
            }
        }
    }
    public static void dfsHelper(ArrayList<Edge> graph[],int curr,boolean vis[]){ // O(V+E)
        // visit curr
        System.out.print(curr+" ");
        vis[curr]=true;
        // call for neighbours
        for(int i=0;i<graph[curr].size();i++){
            Edge e = graph[curr].get(i);
            if(!vis[e.dest]){
                dfsHelper(graph,e.dest,vis);
            }
        }
        // for (int j = 0; j < graph[curr].size(); j++) {
        //     Edge e = graph[curr].get(j);
        //     // Now you have access to e.src, e.dest, and e.wt
        //     System.out.println("Edge from " + e.src + " to " + e.dest + " with weight " + e.wt);
        // }
        
    }
    // static class Pair implements Comparable<Pair>{
    //     int n;
    //     int path;

    //     public Pair(int n,int path){
    //         this.n=n;
    //         this.path=path;
    //     }

    //     @Override
    //     public int compareTo(Pair p2){
    //         return this.path-p2.path; // jo choti h wo phle ret
    //     }
    // }
    // public static void dijkstra(ArrayList<Edge> graph[],int src){
    //     int dis[]=new int[graph.length];//src se ith ka dist
    //     Arrays.fill(dis, Integer.MAX_VALUE);
    //     dis[src]=0;

    //     boolean vis[]= new boolean[graph.length];
    //     PriorityQueue<Pair> pq = new PriorityQueue<>();
    //     pq.add(new Pair(src, 0));

    //     while(!pq.isEmpty()){
    //         Pair curr = pq.remove();

    //         if(!vis[curr.n]){
    //             vis[curr.n]=true;
    //             // neighbours
    //             for(int i=0;i<graph[curr.n].size();i++){
    //                 Edge e = graph[curr.n].get(i);
    //                 int u = e.src;
    //                 int v = e.dest;
    //                 int wt = e.wt;

    //                 if(dis[u]+wt < dis[v]){
    //                     dis[v]=dis[u]+wt;
    //                     pq.add(new Pair(v, dis[v]));
    //                 }
    //             }
    //         }
    //     }
    //     // print all src to vertices shortest distance
    //     for(int i=0;i<dis.length;i++){
    //         System.out.print(dis[i]+" ");
    //     }
    //     System.out.println();
    // }
    static class Pair implements Comparable<Pair>{
        int n; // node
        int path; // path weight
    
        public Pair(int n, int path){
            this.n = n;
            this.path = path;
        }
    
        @Override
        public int compareTo(Pair p2){
            return this.path - p2.path; // Sort by path weight in ascending order
        }
    }
    
    public static void dijkstra(ArrayList<Edge>[] graph, int src){
        int[] dis = new int[graph.length]; // Distance from src to each vertex
        Arrays.fill(dis, Integer.MAX_VALUE); // Initialize all distances to infinity
        dis[src] = 0; // Distance to the source itself is 0
    
        boolean[] vis = new boolean[graph.length]; // Visited array to track processed vertices
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(src, 0));
    
        while (!pq.isEmpty()) {
            Pair curr = pq.remove();
    
            if (!vis[curr.n]) {
                vis[curr.n] = true;
    
                // Process all the neighbors of the current node
                for (int i = 0; i < graph[curr.n].size(); i++) {
                    Edge e = graph[curr.n].get(i);
                    int u = e.src;
                    int v = e.dest;
                    int wt = e.wt;
    
                    // If a shorter path to v is found
                    if (!vis[v] && dis[u] + wt < dis[v]) {
                        dis[v] = dis[u] + wt;
                        pq.add(new Pair(v, dis[v]));
                    }
                }
            }
        }
    
        // Print all src to vertices shortest distances
        for (int i = 0; i < dis.length; i++) {
            System.out.print(dis[i] + " ");
        }
        System.out.println();
    }
    
    public static boolean hasPath(ArrayList<Edge> graph[],int src,int dest,boolean vis[]){
        if(src==dest) return true;
        vis[src]=true;
        // now kya mera neighbour mujhe dest tk pahucha skta h 
        for(int i=0;i<graph[src].size();i++){
            Edge e = graph[src].get(i);
            if(!vis[e.dest] && hasPath(graph, e.dest, dest, vis)){
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {

        int V = 6;
        // array of type arraylist
        ArrayList<Edge>[] graph = new ArrayList[V]; // nulll --> empty Arraylist

        createGraph(graph);

        // 2's neighbour
        // for (int i = 0; i < graph[2].size(); i++) {
        //     // traverse edge
        //     Edge e = graph[2].get(i);
        //     // neighbours will be all destinations
        //     System.out.println(e.dest);
        // }
        bfs(graph);
        System.out.println();
        dfs(graph);
        System.out.println();
        System.out.println(hasPath(graph, 0, 50, new boolean[V]));
        System.out.println();
        int src=0;
        dijkstra(graph, src);
    }
}