class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        //  1. Check Rows
        for(int row = 0; row < 9; row++) {
            unordered_set<char> st;

            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end()) {
                    return false;
                }

                st.insert(board[row][col]);
            }
        }

        //  2. Check Columns
        for(int col = 0; col < 9; col++) {
            unordered_set<char> st;

            for(int row = 0; row < 9; row++) {
                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end()) {
                    return false;
                }

                st.insert(board[row][col]);
            }
        }

        // 3. Check 3x3 Boxes
        for(int boxRow = 0; boxRow < 3; boxRow++) {
            for(int boxCol = 0; boxCol < 3; boxCol++) {

                unordered_set<char> st;

                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {

                        int row = boxRow * 3 + i;
                        int col = boxCol * 3 + j;

                        if(board[row][col] == '.') continue;

                        if(st.find(board[row][col]) != st.end()) {
                            return false;
                        }

                        st.insert(board[row][col]);
                    }
                }
            }
        }

        return true;
    }
};