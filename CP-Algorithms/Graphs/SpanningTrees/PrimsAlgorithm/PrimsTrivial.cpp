#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int V = 5;

int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}
};

int main() {
    int num_edge = 0;
    int selected[V];
    memset(selected, 0, sizeof(selected));
    selected[0] = 1;

    int x, y;
    cout << "Edge : Weight" << endl;
    while(num_edge < V - 1) {
        int mn = INF;
        x = 0;
        y = 0;

        for(int i = 0;i < V;i++) {
            if(selected[i]) {
                for(int j = 0;j < V;j++) {
                    if(!selected[j] && G[i][j]) {
                        if(mn > G[i][j]) {
                            mn = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << G[x][y] << endl;
        selected[y] = true;
        num_edge++;
    }
    
    return 0;
}