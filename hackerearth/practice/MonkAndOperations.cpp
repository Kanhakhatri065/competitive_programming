#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;

    long long int arr[rows][columns];
    for(int i = 0;i < rows;i++) {
        for(int j = 0;j < columns;j++) {
            cin >> arr[i][j];
        }
    }

    long long int v1, v2, v3, v4;
    cin >> v1 >> v2 >> v3 >> v4;

    
    

    long long int sum = 0;

    long long int operation_1_row_sum[rows];
    for(int i = 0;i < rows;i++) {
        sum = 0;
        for(int j = 0;j < columns;j++) {
            sum += abs(arr[i][j] + v1);
        }
        operation_1_row_sum[i] = sum;
    }


    long long int operation_2_row_sum[rows];
    for(int i = 0;i < rows;i++) {
        operation_2_row_sum[i] =  columns * abs(v2);
    }


    long long int operation_3_column_sum[columns];
    for(int i = 0;i < columns;i++) {
        sum = 0;
        for(int j = 0;j < rows;j++) {
            sum += abs(arr[j][i] + v3);
        }
        operation_3_column_sum[i] = sum;
    }

    long long int operation_4_column_sum[columns];
    for(int i = 0;i < columns;i++) {
        operation_4_column_sum[i] = rows * abs(v4);
    }

    long long int operation_1_2_sum = 0;
    for(int i = 0;i < rows;i++) {
        if(operation_1_row_sum[i] >= operation_2_row_sum[i]) {
            operation_1_2_sum += operation_1_row_sum[i];
        } else {
            operation_1_2_sum += operation_2_row_sum[i];
        }
    }

    long long int operation_3_4_sum = 0;
    for(int i = 0;i < columns;i++) {
        if(operation_3_column_sum[i] >= operation_4_column_sum[i]) {
            operation_3_4_sum += operation_3_column_sum[i];
        } else {
            operation_3_4_sum += operation_4_column_sum[i];
        }
    }
    
   if(operation_1_2_sum >= operation_3_4_sum) {
       cout << operation_1_2_sum << endl;
    } else {
        cout << operation_3_4_sum << endl;
    }     

    return 0;
}