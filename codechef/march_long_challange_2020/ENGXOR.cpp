#include <bits/stdc++.h>

using namespace std;

long long int count1s(long long int number) {
    long long int count = 0;

    while(number != 0) {
        count += number & 1;
        number >>= 1;
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases;
    scanf("%d",&testcases);

    for(int i = 0;i < testcases;i++) {
        int numbers, queries;
        scanf("%d %d", &numbers, &queries);

        long long int number[numbers];
        for(int j = 0;j < numbers;j++) {
            scanf("%lld", &number[j]);
        }

        int query[queries];
        for(int j = 0;j < queries;j++) {
            scanf("%d", query[j]);
        }

        for(int j = 0;j < queries;j++) {
            long long int even1s = 0;
            long long int odd1s = 0;
            
            int query_bits = count1s(query[j]);
            int number_bits;
            for(int k = 0;k < numbers;k++) {
                number_bits = count1s(number[k]);

                if((query_bits % 2 == 0 && number_bits % 2 == 0) || (query_bits % 2 != 0 && number_bits % 2 != 0)) {
                    even1s++;
                } else if((query_bits % 2 == 0 && number_bits % 2 != 0) || (query_bits % 2 != 0 && number_bits %2 == 0)) {
                    odd1s++;
                }
            }

            printf("%lld %lld\n", even1s, odd1s);
        }
        
    }

    return 0;
}