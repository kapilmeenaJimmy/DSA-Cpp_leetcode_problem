#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    bool isSafe(vector<string>& board, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }

            if (col - (row - i) >= 0 &&
                board[i][col - (row - i)] == 'Q') {
                return false;
            }

            if (col + (row - i) < n &&
                board[i][col + (row - i)] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(vector<string>& board, int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return result;
    }
};

int main() {
    Solution solution;

    vector<vector<string>> answers = solution.solveNQueens(4);

    cout << "Number of solutions: " << answers.size() << "\n\n";

    for (int i = 0; i < answers.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";

        for (string row : answers[i]) {
            cout << row << '\n';
        }

        cout << '\n';
    }

    return 0;
}
