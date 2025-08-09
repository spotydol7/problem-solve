import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[] indegree;
    static List<List<Integer>> adj;
    static Queue<Integer> ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        indegree = new int[N + 1];
        adj = new ArrayList<>();
        ans = new LinkedList<>();

        for (int i = 0; i < N + 1; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj.get(a).add(b);
            indegree[b]++;
        }

        topologicalSort();

        while(!ans.isEmpty()) {
            System.out.print(ans.poll() + " ");
        }
    }

    static void topologicalSort() {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int i = 1; i < N + 1; i++) {
            if (indegree[i] == 0) pq.offer(i);
        }

        while (!pq.isEmpty()) {
            int cur = pq.poll();
            ans.offer(cur);

            for (Integer i : adj.get(cur)) {
                indegree[i]--;

                if (indegree[i] == 0) pq.offer(i);
            }
        }
    }
}