import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();

        boolean isM = false;
        boolean isO = false;
        boolean isB = false;
        boolean isI = false;
        boolean isS = false;

        for(char c : str.toCharArray()) {
            if (c == 'M') isM = true;
            if (c == 'O') isO = true;
            if (c == 'B') isB = true;
            if (c == 'I') isI = true;
            if (c == 'S') isS = true;
        }

        if (isM && isO && isB && isI && isS) System.out.println("YES");
        else System.out.println("NO");
    }
}
