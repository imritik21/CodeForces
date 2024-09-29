import java.util.*;
public class BipartiteGraph {
    static class Edge{
        int src;
        int dest;

         public Edge(int src,int dest){
            this.src=src;
            this.dest=dest;
        }
    }
    static void createGraph(ArrayList<Edge> graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i] = new ArrayList<>();
        }

        graph[0].add(new Edge(0, 1));
        graph[0].add(new Edge(0, 2));

        
        graph[1].add(new Edge(1, 0));
        graph[1].add(new Edge(1, 3));
        
        graph[2].add(new Edge(2, 0));
        graph[2].add(new Edge(2, 4));
        
        graph[3].add(new Edge(3, 1));
        // graph[3].add(new Edge(3, 4));
        
        graph[4].add(new Edge(4, 2));
        // graph[4].add(new Edge(4, 3));
    }
    // O(V+E)
    //  1.Acycle - always bipartite
    //  2.Even Cycle  - no of nodes is even alays bipartite else non-bipartite
    //  3.Odd cycle -  false
    public static boolean isBipartite(ArrayList<Edge> graph[]){
        int col[] = new int[graph.length];
        for(int i=0;i<col.length;i++){
            col[i]=-1; // no color initially
        }

        Queue<Integer> q = new LinkedList<>();

        for(int i=0;i<graph.length;i++){
            if(col[i]==-1){ // BFS
                q.add(i);
                col[i]=0;//yellow
                while(!q.isEmpty()){
                    int curr = q.remove();
                    for(int j=0;j<graph[curr].size();j++){
                        Edge e = graph[curr].get(j);
                        /// 3 case
                        if(col[e.dest]==-1){
                            int nextCol = col[curr]==0?1:0;
                            col[e.dest]=nextCol;
                            q.add(e.dest);
                        }
                        else if(col[e.dest]==col[curr]){
                            return false; // not bipartite
                        }
                    }
                }
            }
        }
        return true;
    }
    public static void main(String[] args) {
        int V=5;
        ArrayList<Edge> graph[] = new ArrayList[V];
        createGraph(graph);
        System.out.println(isBipartite(graph));
    }

}
