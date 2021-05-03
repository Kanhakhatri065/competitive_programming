#include <bits/stdc++.h>

using namespace std;

int squares(int i) {
    if(i & 1) {
        return i / 4 * 2 + 1;
    }

    return (i - 1) / 4 * 2 + 2;
}

int bishop_placements(int N, int K) {
    if(K > 2 * N - 1) {
        return 0;
    }

    vector<vector<int>> D(N * 2, vector<int>(K + 1));

    for(int i = 0;i < N * 2;i++) D[i][0] = 1;
    D[1][1] = 1;

    for(int i = 1;i < N * 2;i++) {
        for(int j = 1;j <= K;j++) {
            D[i][j] = D[i - 2][j] + D[i - 2][j - 1] * (squares(i) - j + 1);
        }
    }

    int ans = 0;
    for(int i = 0;i <= K;i++) {
        ans += D[N * 2 - 1][i] * D[N * 2 - 2][K - i];
    }

    return ans;
}

int main() {
    int N = 5, K = 2;
    cout << "For N = " << N << " and K = " << K;
    cout << " answer is : " << bishop_placements(N, K) << endl;

    return 0;
}
