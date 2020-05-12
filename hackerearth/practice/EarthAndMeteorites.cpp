#include <bits/stdc++.h>

using namespace std;

int main() {
    int edge_x_coordinate, edge_y_coordinate, queries;
    cin >> edge_x_coordinate >> edge_y_coordinate >> queries;

    int earth[edge_x_coordinate][edge_y_coordinate];
    for(int i = 0;i < edge_x_coordinate;i++) {
        for(int j = 0;j < edge_y_coordinate;j++) {
            earth[i][j] = 0;
        }
    }

    for(int i = 0;i < edge_x_coordinate;i++) {
        for(int j = 0;j < edge_y_coordinate;j++) {
            cout << earth[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}