#include <iostream>

using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;



int main() {
    FAST_IO

    int testcases;
    cin >> testcases;

    ll pages;
    while(testcases--) {
        cin >> pages;
        
        if(pages <= 3) {
            printf("1\n");
            if(pages == 1) {
                printf("1 1\n");
            } else if(pages == 2) {
                printf("2 1 2\n");
            } else if(pages == 3) {
                printf("3 1 2 3\n");
            }
        } else {
            printf("%lld\n", (pages / 2));
            printf("3 1 2 3\n");
            for(ll i = 4;i <= pages;i++) {
                if(i % 2 == 0) {
                    if(i < pages) {
                        printf("2 %lld %lld\n", i++, i);
                    } else if(i == pages) {
                        printf("1 %lld\n", i);
                    }
                }
            }
            
        }

    }

    return 0;
}