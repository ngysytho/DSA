package blind75;

import java.util.*;
import java.io.*;

class Main {

    static class Solution {

        public boolean dfs(char[][] board, String word, int[][] dir,
            int n, int m, int start) {

            if (n < 0 || n >= board.length ||
                m < 0 || m >= board[0].length ||
                board[n][m] != word.charAt(start)) {
                return false;
            }

            if (start == word.length() - 1) {
                return true;
            }

            char temp = board[n][m];
            board[n][m] = '#';

            for (int[] x : dir) {
                int newN = n + x[0];
                int newM = m + x[1];

                if (dfs(board, word, dir, newN, newM, start + 1)) {
                    board[n][m] = temp;
                    return true;
                }
            }

            board[n][m] = temp;

            return false;
        }

        public boolean exist(char[][] board, String word) {

            int[][] dir = {
                {0, 1},
                {0, -1},
                {-1, 0},
                {1, 0}
            };

            int n = board.length;
            int m = board[0].length;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    if (board[i][j] == word.charAt(0)) {
                        if (dfs(board, word, dir, i, j, 0)) {
                            return true;
                        }
                    }
                }
            }

            return false;
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st =
            new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        char[][] board = new char[n][m];

        for (int i = 0; i < n; i++) {
            String row = br.readLine();
            board[i] = row.toCharArray();
        }

        String word = br.readLine();

        Solution solution = new Solution();

        boolean ans = solution.exist(board, word);

        System.out.println(ans);
    }
}