#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool judgeRow(const vector<vector<char>> &board, int r) {
        char buf[10] = {0};
        for (int i = 0; i < 9; i++)
            if (board[r][i] != '.') {
                if (++buf[board[r][i] - '0'] > 1)
                    return false;
            }
        return true;
    }
    bool judgeCol(const vector<vector<char>> &board, int c) {
        char buf[10] = {0};
        for (int i = 0; i < 9; i++)
            if (board[i][c] != '.') {
                if (++buf[board[i][c] - '0'] > 1)
                    return false;
            }
        return true;
    }
    bool judgeMatrix(const vector<vector<char>> &board) {
        for (int i = 0, j =0; j < 9; i += 3) {
            char buf[10] = {0};
            for (int p = i; p < i+3; p++) {
                for (int q = j; q < j + 3; q++) {
                    if (board[p][q] != '.') 
                        if (++buf[board[p][q] - '0'] > 1)
                            return false;
                }
            }
            if (i == 9) {
                i = 0;
                j += 3;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            if (judgeRow(board, i) == false || judgeCol(board, i) == false)
                return false;
        return judgeMatrix(board);
    }
};
int main()
{
	freopen("in-36", "r", stdin);
	Solution s;
	vector<vector<char>> b(9, vector<char>(9, 0));
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) 
			cin >> b[i][j];
	cout << s.isValidSudoku(b) << endl;
}
