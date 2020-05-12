#include <bits/stdc++.h>

using namespace std;

int main() {
    int rows, columns, rings;
    cin >> rows >> columns >> rings;

    int total = 0;

    int start_row = 1;
    int end_row = rows;

    int start_column = 1;
    int end_column = columns;

    for(int i = 0;i < rings;i++) {
        total += ((2 * (end_row - start_row + 1)) + (2 * (end_column - start_column + 1)) - 4);
        
        start_row += 2;
        start_column += 2;

        end_row -= 2;
        end_column -= 2;
    }

    cout << total << endl;

    return 0;
}