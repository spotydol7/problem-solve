import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] P, S, cards;
    
    static void shuffle() {
        int[] temp = new int[N];
        for (int i = 0; i < N; i++) {
            temp[S[i]] = cards[i];
        }
        cards = temp;
    }
    
    static boolean check() {
        for (int j = 0; j < N; j++) {
            int orig = cards[j];
            if (j % 3 != P[orig]) return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine().trim());
        P = new int[N];
        S = new int[N];
        cards = new int[N];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            P[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            S[i] = Integer.parseInt(st.nextToken());
        }
        
        for (int i = 0; i < N; i++) {
            cards[i] = i;
        }
        
        Set<String> visited = new HashSet<>();
        int cnt = 0;
        int ans = -1;

        while (true) {
            if (check()) {
                ans = cnt;
                break;
            }
            String state = Arrays.toString(cards);
            
            if (visited.contains(state)) {
                ans = -1;
                break;
            }
            visited.add(state);
            
            shuffle();
            cnt++;
        }

        System.out.println(ans);
    }
}
