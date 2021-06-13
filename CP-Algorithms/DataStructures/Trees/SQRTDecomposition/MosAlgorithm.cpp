#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int cnt[N], a[N];
int distinct_elements;
void remove(int idx) {
    cnt[a[idx]]--;
    if(cnt[a[idx]] == 0) {
        distinct_elements--;
    }
}

void add(int idx) {
    cnt[a[idx]]++;
    if(cnt[a[idx]] == 1) {
        distinct_elements++;
    }
}

int get_answer() {
    return distinct_elements;
}

int block_size;

struct Query {
    int l, r, idx;
    bool operator <(Query other) const {
        return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answer(int(queries.size()));
    sort(queries.begin(), queries.end());

    int cur_l = 0, cur_r = -1;
    for(Query q : queries) {
        while(cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }

        while(cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }

        while(cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }

        while(cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }

        answer[q.idx] = get_answer();
    }

    return answer;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    block_size = (int) sqrt(n + 0.0) + 1; 
    int q;
    cin >> q;
    vector<Query> queries;
    for(int i = 0;i < q;i++) {
        int l, r;cin >> l >> r;
        queries.push_back({l, r, i});
    }

    distinct_elements = 0;
    vector<int> ans = mo_s_algorithm(queries);
    for(int i = 0;i < q;i++) cout << ans[i] << endl;
    return 0;
}
