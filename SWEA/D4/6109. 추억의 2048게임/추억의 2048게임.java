import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;
 
public class Solution {
    private static int boardSize;
    private static int[][] board;
 
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(reader.readLine());
        StringBuilder output = new StringBuilder();
        StringTokenizer tokenizer;
 
        for (int t = 0; t < testCases; t++) {
            tokenizer = new StringTokenizer(reader.readLine());
            boardSize = Integer.parseInt(tokenizer.nextToken());
            String direction = tokenizer.nextToken();
 
            // 보드 입력받기
            board = new int[boardSize][boardSize];
            for (int i = 0; i < boardSize; i++) {
                tokenizer = new StringTokenizer(reader.readLine());
                for (int j = 0; j < boardSize; j++) {
                    board[i][j] = Integer.parseInt(tokenizer.nextToken());
                }
            }
 
            output.append("#").append(t + 1).append("\n");
            if (direction.equals("up"))
                slideAndMerge(false, 0, boardSize, 1);
            else if (direction.equals("down"))
                slideAndMerge(false, boardSize - 1, -1, -1);
            else if (direction.equals("right"))
                slideAndMerge(true, boardSize - 1, -1, -1);
            else  // left
                slideAndMerge(true, 0, boardSize, 1);
 
            for (int i = 0; i < boardSize; i++) {
                for (int j = 0; j < boardSize; j++) {
                    output.append(board[i][j]).append(" ");
                }
                output.append("\n");
            }
        }
        System.out.println(output);
    }
 
    private static void slideAndMerge(boolean isHorizontal, int startIndex, int boundary, int step) {
        int rowIndex = 0;
        int colIndex = 0;
        if (isHorizontal)
            colIndex = startIndex;
        else
            rowIndex = startIndex;
 
        while (!((isHorizontal) ? rowIndex == boardSize : colIndex == boardSize)) {
            Deque<Integer> tileQueue = new LinkedList<>();
            boolean mergedFlag = false;
            if (isHorizontal)
                colIndex = startIndex;
            else
                rowIndex = startIndex;
 
            while (!((isHorizontal) ? colIndex == boundary : rowIndex == boundary)) {
                if (board[rowIndex][colIndex] != 0) {
                    if (tileQueue.isEmpty())
                        tileQueue.add(board[rowIndex][colIndex]);
                    else if (mergedFlag || tileQueue.peekLast() != board[rowIndex][colIndex]) {
                        tileQueue.add(board[rowIndex][colIndex]);
                        mergedFlag = false;
                    } else {
                        tileQueue.add(tileQueue.pollLast() * 2);
                        mergedFlag = true;
                    }
                }
                board[rowIndex][colIndex] = 0;
                if (isHorizontal)
                    colIndex += step;
                else
                    rowIndex += step;
            }
 
            if (isHorizontal) {
                int fillIndex = startIndex;
                while (!tileQueue.isEmpty()) {
                    board[rowIndex][fillIndex] = tileQueue.poll();
                    fillIndex += step;
                }
                rowIndex++;
            } else {
                int fillIndex = startIndex;
                while (!tileQueue.isEmpty()) {
                    board[fillIndex][colIndex] = tileQueue.poll();
                    fillIndex += step;
                }
                colIndex++;
            }
        }
    }
}
