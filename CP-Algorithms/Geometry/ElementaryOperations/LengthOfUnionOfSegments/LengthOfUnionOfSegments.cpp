#include <bits/stdc++.h>
using namespace std;

int length_union(vector<pair<int, int>> a) {
    int n = int(a.size());

    vector<pair<int, bool>> x(n * 2);
    for(int i = 0;i < n;i++) {
        x[i << 1] = {a[i].first, false};
        x[i << 1 | 1] = {a[i].second, true};
    }
    
    sort(x.begin(), x.end());
    int result = 0;
    int c = 0;

    for(int i = 0;i < (n << 1);i++) {
        if(i > 0 && (x[i].first > x[i - 1].first) && c > 0) {
            result += (x[i].first - x[i - 1].first);
        }

        if(x[i].second) c--;
        else c++;
    }

    return result;
}

int main() {
    int n;
    cout << "No. of segments : " << endl;
    cin >> n;

    vector<pair<int, int>> store(n);
    for(int i = 0;i < n;i++) cin >> store[i].first >> store[i].second;

    int ans = length_union(store);
    cout << "Length of the union of segments is : " << ans << endl;

    return 0;
}
