#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define ff first
#define ss second 
#define pp pair
#define ULRED 1000000007
#define MS(x,y) (x-y>0?x-y:y-x) 
#define MX(x,y) x>y?x:y
#define MN(x,y) x>y?y:x
#define MX3(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))

void swapll(ll *a,ll *b){ll tmp=*a;*a=*b;*b=tmp;}
void swapc(char *a,char *b){char tmp=*a;*a=*b;*b=tmp;}
/*----------------------------------------------------------------*/

int main() {
    FAST_IO

    string str1, str2;
    cin >> str1 >> str2;

    int num1 = str1[1], num2 = str2[1], num3 = str1[0], num4 = str2[0];

    int dist1 = max(num1 - num2, num2 - num1);
    int dist2 = max(num3 - num4, num4 - num3);

    if(dist1 == 0 && dist2 == 0) {
        cout << "0" << endl;
    } else {
        if(dist1 < dist2) {
            cout << dist2 << endl;
            if(num1 == num2) {
                for(int i = 1;i <= dist2;i++) {
                    if(num3 < num4) {
                        cout << "R" << endl;
                    } else {
                        cout << "L" << endl;
                    }
                }
            } else if(num1 != num2) {
                if(num1 < num2 && num3 < num4) {
                    while(num1 != num2) {
                        cout << "RU" << endl;
                        num1++;
                        num3++;
                    }

                    while(num3 != num4) {
                        cout << "R" << endl;
                        num3++;
                    }
                } else if(num1 < num2 && num3 > num4) {
                    while(num1 != num2) {
                        cout << "LU" << endl;
                        num1++;
                        num3--;
                    }

                    while(num3 != num4) {
                        cout << "L" << endl;
                        num3--;
                    }
                } else if(num1 > num2 && num3 < num4) {
                    while(num1 != num2) {
                        cout << "RD" << endl;
                        num1--;
                        num3++;
                    }
                    
                    while(num3 != num4) {
                        cout << "R" << endl;
                        num3++;
                    }
                } else if(num1 > num2 && num3 > num4) {
                    while(num1 != num2) {
                        cout << "LD" << endl;
                        num1--;
                        num3--;
                    }

                    while(num3 != num4) {
                        cout << "L" << endl;
                        num3--;
                    }
                }
            }
        } else {
            cout << dist1 << endl;
            if(num3 == num4) {
                for(int i = 1;i <= dist1;i++) {
                    if(num1 < num2) {
                        cout << "U" << endl;
                    } else {
                        cout << "D" << endl;
                    }
                }
            } else if(num3 != num4){
                if(num1 < num2 && num3 < num4) {
                    while(num3 != num4) {
                        cout << "RU" << endl;
                        num3++;
                        num1++;
                    }

                    while(num1 != num2) {
                        cout << "U" << endl;
                        num1++;
                    }
                } else if(num1 < num2 && num3 > num4) {
                    while(num3 != num4) {
                        cout << "LU" << endl;
                        num3--;
                        num1++;
                    }

                    while(num1 != num2) {
                        cout << "U" << endl;
                        num1++;
                    }
                } else if(num1 > num2 && num3 < num4) {
                    while(num3 != num4) {
                        cout << "RD" << endl;
                        num3++;
                        num1--;
                    }

                    while(num1 != num2) {
                        cout << "D" << endl;
                        num1--;
                    }
                } else if(num1 > num2 && num3 > num4) {
                    while(num3 != num4) {
                        cout << "LD" << endl;
                        num3--;
                        num1--;
                    }

                    while(num1 != num2) {
                        cout << "D" << endl;
                        num1--;
                    }
                }
            }
        }
    }

    return 0;
}