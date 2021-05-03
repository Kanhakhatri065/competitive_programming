#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int compute_rank(vector<vector<double>> A) {
    int n = A.size();
    int m = A[0].size();

    int rank = 0;
    vector<bool> row_selected(n, false);
    for (int i = 0; i < m; ++i) {
        int j;
        for (j = 0; j < n; ++j) {
            if (!row_selected[j] && abs(A[j][i]) > EPS)
                break;
        }

        if (j != n) {
            ++rank;
            row_selected[j] = true;
            for (int p = i + 1; p < m; ++p)
                A[j][p] /= A[j][i];
            for (int k = 0; k < n; ++k) {
                if (k != j && abs(A[k][i]) > EPS) {
                    for (int p = i + 1; p < m; ++p)
                        A[k][p] -= A[j][p] * A[k][i];
                }
            }
        }
    }
    return rank;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<double>> v(n, vector<double>(m));
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> v[i][j];

    cout << "Rank of the given matrix is : " << compute_rank(v) << endl;

    return 0;
}
