#include <bits/stdc++.h>
using namespace std;

struct pt{
    long long x, y;
    pt operator + (const pt & p) const {
        return pt{x + p.x, y + p.y};
    }
    pt operator - (const pt & p) const {
        return pt{x - p.x, y - p.y};
    }
    long long cross(const pt & p) const {
        return x * p.y - y * p.x;
    }
};

void reorder_polygon(vector<pt> & P){
    size_t pos = 0;
    for(size_t i = 1; i < P.size(); i++){
        if(P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
            pos = i;
    }
    rotate(P.begin(), P.begin() + pos, P.end());
}

vector<pt> minkowski(vector<pt> P, vector<pt> Q){
    // the first vertex must be the lowest
    reorder_polygon(P);
    reorder_polygon(Q);
    // we must ensure cyclic indexing
    P.push_back(P[0]);
    P.push_back(P[1]);
    Q.push_back(Q[0]);
    Q.push_back(Q[1]);
    // main part
    vector<pt> result;
    size_t i = 0, j = 0;
    while(i < P.size() - 2 || j < Q.size() - 2){
        result.push_back(P[i] + Q[j]);
        auto cross = (P[i + 1] - P[i]).cross(Q[j + 1] - Q[j]);
        if(cross >= 0)
            ++i;
        if(cross <= 0)
            ++j;
    }
    return result;
}

int main() {
    cout << "Enter the number of vertices in the first polygon : " << endl;
    int n;cin >> n;
    vector<pt> P(n);
    cout << "Enter the vertices of the first polygon : " << endl;
    for(int i = 0;i < n;i++) cin >> P[i].x >> P[i].y;

    cout << "Enter the number of vertices in the second polygon : " << endl;
    int m;cin >> m;
    vector<pt> Q(m);
    cout << "Enter the vertices of the second polygon : " << endl;
    for(int i = 0;i < m;i++) cin >> Q[i].x >> Q[i].y;

    vector<pt> result = minkowski(P, Q);
    cout << "The number of vertices in the sum of polygon are : " << int(result.size()) << endl;
    cout << "The vertices are : " << endl;
    for(int i = 0;i < int(result.size());i+= 1) cout << result[i].x << " " << result[i].y << endl;


    return 0;
}
