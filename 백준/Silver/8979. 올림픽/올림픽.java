import java.io.*;
import java.util.*;

public class Main {

    static class Medals {
        int country, gold, silver, bronze;
        Medals(int country, int gold, int silver, int bronze) {
            this.country = country;
            this.gold = gold;
            this.silver = silver;
            this.bronze = bronze;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        List<Medals> medals = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int country = Integer.parseInt(st.nextToken());
            int gold = Integer.parseInt(st.nextToken());
            int silver = Integer.parseInt(st.nextToken());
            int bronze = Integer.parseInt(st.nextToken());
            medals.add(new Medals(country, gold, silver, bronze));
        }

        medals.sort((a, b) -> {
            if (a.gold != b.gold) return b.gold - a.gold;
            if (a.silver != b.silver) return b.silver - a.silver;
            return b.bronze - a.bronze;
        });

        int rank = 1;
        int prevG = -1, prevS = -1, prevB = -1;

        for (int i = 0; i < medals.size(); i++) {
            Medals cur = medals.get(i);

            if (i == 0 || cur.gold != prevG || cur.silver != prevS || cur.bronze != prevB) {
                rank = i + 1;
                prevG = cur.gold;
                prevS = cur.silver;
                prevB = cur.bronze;
            }

            if (cur.country == K) {
                System.out.println(rank);
                return;
            }
        }
    }
}