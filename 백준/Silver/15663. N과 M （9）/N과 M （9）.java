import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n;
    static int m;
    static int[] arr;     // 현재 조합을 저장할 배열
    static int[] nums;    // 입력받은 숫자들을 저장
    static boolean[] visited; // 각 숫자(인덱스) 방문 여부 체크

    public static void dfs(int level) {
        if(level == m) {
            StringBuilder sb = new StringBuilder();
            for (int num : arr) {
                sb.append(num).append(" ");
            }
            System.out.println(sb.toString().trim());
            return;
        }
        int last = Integer.MIN_VALUE;  // 같은 레벨에서 중복되는 숫자 사용을 방지하기 위한 변수
        for (int i = 0; i < n; i++) {
            // 이미 방문한 숫자는 건너뜁니다.
            // 또한, 같은 레벨에서 이전에 사용한 동일한 숫자는 건너뜁니다.
            if (!visited[i] && last != nums[i]) {
                visited[i] = true;
                arr[level] = nums[i];
                last = nums[i];  // 현재 레벨에서 사용한 숫자 기록
                dfs(level + 1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[m];
        nums = new int[n];
        visited = new boolean[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        // 중복 제거가 아니라, 정렬만 합니다.
        Arrays.sort(nums);
        dfs(0);
    }
}
