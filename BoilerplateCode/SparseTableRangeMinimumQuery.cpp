//MAXN can be upto 1e7
const int MAXN = 1e5 + 5;
const int K = 25;

int log_of_2[MAXN + 1];
int st[MAXN][K + 1];

int n;
void precomputation(vector<int> arr) {
    log_of_2[1] = 0;
    for(int i = 2;i <= MAXN;i++) log_of_2[i] = log_of_2[i / 2] + 1;
    
    for(int i = 0;i < n;i++) st[i][0] = arr[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]); 
}

int query(int L, int R) {
    int j = log_of_2[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}
