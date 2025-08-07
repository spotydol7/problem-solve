import java.util.*;

class Solution {
    class Word {
        int depth;
        String word;
        
        Word(int depth, String word) {
            this.depth = depth;
            this.word = word;
        }
    }
    
    public boolean isConvertable(String a, String b) {
        int cnt = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) cnt++;
        }
        if (cnt == 1) return true;
        else return false;
    }
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        boolean[] visited = new boolean[words.length];
        
        Queue<Word> q = new LinkedList<>();
        q.add(new Word(0, begin));
        
        while (!q.isEmpty()) {
            Word cur = q.poll();
            
            for (int i = 0; i < words.length; i++) {
                if (!visited[i] && isConvertable(cur.word, words[i])) {
                    if (words[i].equals(target)) return cur.depth + 1;
                    visited[i] = true;
                    q.add(new Word(cur.depth + 1, words[i]));
                }
            }
        }
        
        return 0;
    }
}