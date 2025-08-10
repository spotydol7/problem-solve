import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Node implements Comparable<Node> {
    int node;
    int weight;

    public Node(int node, int weight) {
        this.node = node;
        this.weight = weight;
    }

    @Override
    public int compareTo(Node o) {
        return Integer.compare(this.weight, o.weight);
    }
}

public class Main {
    private static final int INF = Integer.MAX_VALUE;
    private static List<List<Node>> adj = new ArrayList<>();
    private static int[] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());

        for (int i = 0; i < V + 1; i++) {
            adj.add(new ArrayList<>());
        }
        dist = new int[V + 1];
        Arrays.fill(dist, INF);

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            adj.get(u).add(new Node(v, w));
        }

        dijkstra(start);

        for (int i = 1; i <= V; i++) {
            if (dist[i] != INF) System.out.println(dist[i]);
            else System.out.println("INF");
        }
    }

    public static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();

        pq.add(new Node(start, 0));
        dist[start] = 0;

        while(!pq.isEmpty()) {
            Node cur = pq.poll();
            int curNode = cur.node;
            int curWeight = cur.weight;

            if (dist[curNode] < curWeight) continue;
            
            for (Node next : adj.get(curNode)) {
                int nextNode = next.node;
                int nextWeight = next.weight;
                if (curWeight + nextWeight < dist[nextNode]) {
                    dist[nextNode] = curWeight + nextWeight;
                    pq.add(new Node(nextNode, dist[nextNode]));
                }
            }
        }
    }
}