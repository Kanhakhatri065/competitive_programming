#include <bits/stdc++.h>

using namespace std;

long long int Log2(long long int x) {
    if(x <= 1) {
        return 0;
    }

    return Log2(floor(x / 2)) + 1;
}

long long int F(vector<int> A, vector<int> B) {
    vector<int> posA;
    vector<int> posB;
    
    map<int, int> m;
    for(int j = 0;j < A.size();j++) {
        m[A[j]] = j;
    }

    map<int, int>::iterator it;
    for(it = m.begin();it != m.end();++it) {
        posA.push_back(it->second);
    }

    m.clear();

    for(int j = 0;j < B.size();j++) {
        m[B[j]] = j;
    }

    for(it = m.begin();it != m.end();++it) {
        posB.push_back(it->second);
    }

    long long int ret = 0;
    for(int i = 0;i < A.size();i++) {
        ret += Log2(abs(posA[i] - posB[i]));
    }

    return ret;
}


int main() {
    int testcases;
    cin >> testcases;

    int n, v;
    for(int i = 0;i < testcases;i++) {
        cin >> n >> v;

        int temp;

        vector<int> p;
        for(int j = 0;j < n;j++) {
            cin >> temp;
            p.push_back(temp);
        }

        vector<int> q;
        for(int j = 0;j < n;j++) {
            cin >> temp;
            q.push_back(temp);
        }

        vector<int> temp1;
        vector<int> temp2;

        vector<int> r;
        long long int result = 1;
        for(int j = 0;j < v - 1;j++) {
            for(int k = q.size() - 1;k > q.size() - 1 - j;k--) {
                temp1.push_back(q[k]);
            }

            for(int k = 0;k < q.size() - j;k++) {
                temp2.push_back(q[k]);
            }
            

            for(int k = 0;k < temp1.size();k++) {
                r.push_back(temp1[k]);
            }
            
            for(int k = 0;k < temp2.size();k++) {
                r.push_back(temp2[k]);
            }

            result *= F(p, r);
            r.clear();
            temp1.clear();
            temp2.clear();
        }

        result %= 998244353;

        cout << result << endl;
    }

    return 0;
}