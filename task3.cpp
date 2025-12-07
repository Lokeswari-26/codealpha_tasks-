#include <iostream>
using namespace std;

bool isSafe(int grid[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (grid[r + startRow][c + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[9][9], int row, int col) {
    if (row == 8 && col == 9) return true;
    if (col == 9) { row++; col = 0; }
    if (grid[row][col] != 0) return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) return true;
        }
        grid[row][col] = 0;
    }

    return false;
}

void printGrid(int grid[9][9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++)
            cout << grid[r][c] << " ";
        cout << endl;
    }
}

int main() {
    int grid[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        cout << "No solution exists";

    return 0;
}
