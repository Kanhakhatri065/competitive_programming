#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
/*----------------------------------------------------------------*/

bool isGood(ll number) {
    ll count_two = 0;
    
    while(true) {
        if(number % 2 == 0) {
            count_two++;
            number /= 2;
        } else {
            break;
        }

        if(count_two > 1) {
            break;
        }
    }

    if(count_two == 1) {
        return false;
    }
    return true;
}


int main() {

    ll testcases;
    scanf("%lld", &testcases);

    ll size;
    while(testcases--) {
        scanf("%lld", &size);
        list<ll> evenIndex;

        vector<ll> v(size, 0);
        for(ll i = 0;i < size;i++) {
            scanf("%lld", &v[i]);
            

            if(v[i] % 2 == 0) {
                evenIndex.push_back(i);
            }
        }
       
        ll total = (size * (size + 1)) / 2;

        ll count = 0;

        for(ll i = 0;i < size;i++) {
            if(!isGood(v[i])) {
                evenIndex.pop_front();
                if(!evenIndex.empty()) {
                    ll temp = evenIndex.front();
                    count += (temp - i);
                } else {
                    count += size - i;
                }
            } else {
                if(v[i] % 2 == 0) {
                    evenIndex.pop_front();
                } else {
                    if(!evenIndex.empty()) {
                        ll temp = evenIndex.front();
                        evenIndex.pop_front();
                        if(!isGood(v[temp]) && !evenIndex.empty()) {
                            ll temp1 = evenIndex.front();
                            count += (temp1 - temp);
                        } else if(!isGood(v[temp]) && evenIndex.empty()) {
                            count += size - temp;
                        }
                        evenIndex.push_front(temp);
                    }
                }
            }             
        }

        /*
        vector<ll> products(size, 1);
        for(ll i = 0;i < size;i++) {
            for(ll j = 0;j <= i;j++) {
                products[j] *= v[i];
                if(isGood(products[j])) {
                    count++;
                }
            }
        }
        */

        count = total - count;
      
        printf("%lld\n", count);
    }
    return 0;
}