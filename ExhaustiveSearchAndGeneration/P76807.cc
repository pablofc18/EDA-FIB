#include <iostream>
#include <vector>
using namespace std;

////////////////////
////ME SUPERA :c////
////////////////////

#define COLS 9
#define ROWS 9
typedef vector<vector<int>> Board;

void read_sudoku(Board& B) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            char ch; cin >> ch;
            int num;
            if (ch == '.') num = 0;
            else num = ch - '0';
            B[i][j] = num;
        }
    }

}

// void print_sudoku(const Board& B) {
//     for (int i = 0; i < ROWS; ++i) {
//         for (int j = 0; j < COLS; ++j) {
//             cout << B[i][j];
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

int main() {
    int n; cin >> n;
    Board B = Board(ROWS, vector<int>(COLS));
    while (n--) {
        read_sudoku(B);


    }

    //print_sudoku(B);
}
