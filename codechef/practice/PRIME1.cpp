#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a == 1) a++;
        for(int i = a;i <= b;i++) {
            bool flag = true;
            for(int j = 2;j <= sqrt(i);j++) {
                if(i % j == 0) {
                    flag = false;
                    break;
                }
            }

            if(flag) printf("%d\n", i);
        }
        printf("\n");
    }
    return 0;
}
