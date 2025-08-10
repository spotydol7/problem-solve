
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

    Node(int node, int weight) {
        this.node = node;
        this.weight = weight;
    }

    @Override
    public int compareTo(Node o) {
         return Integer.compare(this.weight, o.weight); // 왼쪽 숫자가 더 크면 1 반환
    }
}

public class Main {
    private static int[] dist;
    private static List<List<Node>> adj = new ArrayList<>();
    private static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        for (int i = 0; i < N + 1; i++) {
            adj.add(new ArrayList<>());
        }
        dist = new int[N + 1];
        Arrays.fill(dist, INF);

        StringTokenizer st;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            adj.get(u).add(new Node(v, w));
        }

        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        dijkstra(start);

        System.out.println(dist[end]);
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
                if (dist[nextNode] > curWeight + nextWeight) {
                    dist[nextNode] = curWeight + nextWeight;
                    pq.add(new Node(nextNode, dist[nextNode]));
                }
            }
        }
    }
}
