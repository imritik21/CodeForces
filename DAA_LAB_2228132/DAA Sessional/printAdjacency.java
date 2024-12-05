import java.util.*;

class CreatingGraph{
    static class Edge{
        int src;
        int dest;
        int wt;

        public Edge(int src,int dest,int wt){
            this.src=src;
            this.dest=dest;
            this.wt=wt;
        }
    }
    static void createGraph(ArrayList<Edge> graph[]){
        graph[0].add(new Edge(0, 1, 2));
        graph[0].add(new Edge(0, 2, 4));
        
        graph[1].add(new Edge(1, 3, 7));
        graph[1].add(new Edge(1, 2, 1));
        
        graph[2].add(new Edge(2, 4, 3));
        
        graph[3].add(new Edge(3, 5, 1));
        
        graph[4].add(new Edge(1, 3, 7));
        graph[4].add(new Edge(4, 5, 5));
    }
    static void print(ArrayList<Edge> graph[],int V){
        
    }
}
public class printAdjacency {
    public static void main(String[] args) {
        int V = 6;
        ArrayList<Edge> graph[] = new ArrayList[V];
        createGraph(graph);


    }    
}
