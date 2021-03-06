//MAXN value can be upto 1e7
const int MAXN = 1e5 + 5;
const int K = 25;

long long st[MAXN][K + 1];
int n;
void precomputation(vector<int> arr) {
    for(int i = 0;i < n;i++) st[i][0] = arr[i];

    for(int j = 1;j <= K;j++) {
        for(int i = 0;i + (1 << j) <= n;i++) {
            st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
        }
    }
}

long long query(int l, int r) {
    long long sum = 0;
    for(int j = K;j >= 0;j--) {
        if((1 << j) <= (r - l + 1)) {
            sum += st[l][j];
            l += (1 << j);
        }
    }

    return sum;
}
