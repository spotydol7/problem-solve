import java.util.*;

class Solution {
    public int solution(String s) {
        int n = s.length();
        int maxLen = 1;

        for (int center = 0; center < n; center++) {
            // 홀수
            maxLen = Math.max(maxLen, expand(s, center, center));

            // 짝수
            maxLen = Math.max(maxLen, expand(s, center, center + 1));
        }

        return maxLen;
    }

    int expand(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }
}