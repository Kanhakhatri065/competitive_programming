#include <iostream>

using namespace std;

int main() {
    int num_students, num_rows, max_capacity_of_row;
    cin >> num_students >> num_rows >> max_capacity_of_row;

    int arr[num_students];
    for(int i = 0;i < num_students;i++) {
        cin >> arr[i];
    }

    int rows[num_rows] = {0};
    
    int count = 0;
    for(int i = 0;i < num_students;i++) {
        if(rows[arr[i] - 1] < max_capacity_of_row) {
            rows[arr[i] - 1]++;
        } else {
            count++;

            int find_row = arr[i];
            int row_count = 0;
            while(true) {
                if(rows[find_row] < max_capacity_of_row) {
                    rows[find_row]++;
                    break;
                } else {
                    find_row++;
                    if(find_row == num_rows) {
                        find_row = 0;
                    }
                }
                row_count++;
                if(row_count == num_rows) {
                    break;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}