class Solution {
    public boolean isValidSudoku(char[][] board) {

        for ( int i = 0; i < 9; i ++) {
            Set<Character> rows = new HashSet<>();
            Set<Character> columns = new HashSet<>(); 
            Set<Character> squares = new HashSet<>();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!rows.add(board[i][j])){
                        return false;
                    } 
                }
                if (board[j][i] != '.') {
                    if (!columns.add(board[j][i])){
                        return false;
                    }
                }
                if (board[3 * ((int) i / 3) + ((int) j / 3)][3 * (i%3) + (j % 3)] != '.') {
                    if (!squares.add(board[3 * ((int) i / 3) + ((int) j / 3)][3 * (i%3) + (j % 3)])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
