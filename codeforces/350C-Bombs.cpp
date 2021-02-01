/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> arr;
    int s = 0;
    for(int i = 0;i < n;i++) {
        int x, y;
        cin >> x >> y;

        arr.push_back({abs(x) + abs(y), {x, y}});

        if(abs(x) && abs(y)) s+= 2;
        else s += 1;
    }

    sort(arr.begin(), arr.end());
    printf("%d\n", (s + n) * 2);

    for(int i = 0;i < n;i++) {
        int x = arr[i].second.first;
        int y = arr[i].second.second;

        if(abs(x)) printf("1 %d %c\n", abs(x), x > 0 ? 'R' : 'L');
        if(abs(y)) printf("1 %d %c\n", abs(y), y > 0 ? 'U' : 'D');

        printf("2\n");

        if(abs(x)) printf("1 %d %c\n", abs(x), x > 0 ? 'L' : 'R');
        if(abs(y)) printf("1 %d %c\n", abs(y), y > 0 ? 'D' : 'U');

        printf("3\n");
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    solve();
    return 0;
}