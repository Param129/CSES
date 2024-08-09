#include <iostream>
#include <vector>

using namespace std;

const int N = 8;
int dir[8][2] = {{-2, 1}, {1, -2}, {2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool isValid(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

bool solveKTUtil(vector<vector<int>>& board, int curr_x, int curr_y, int movei) {
    if (movei == 64) return true;

    for (int i = 0; i < 8; i++) {
        int next_x = curr_x + dir[i][0];
        int next_y = curr_y + dir[i][1];

        if (isValid(next_x, next_y, board)) {
            board[next_x][next_y] = movei;
            if (solveKTUtil(board, next_x, next_y, movei + 1)) return true;
            else
                board[next_x][next_y] = -1; // backtrack
        }
    }
    return false;
}

void printSolution(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] + 1 << " "; // +1 to convert from 0-based index
        }
        cout << endl;
    }
}

int main() {
    int x, y;
    cin >> y >> x;
    x--; // Convert to 0-based index
    y--;

    vector<vector<int>> board(N, vector<int>(N, -1));

    board[x][y] = 0; // Start from the given position

    if (solveKTUtil(board, x, y, 1)) {
        printSolution(board);
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
