#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = int(s.size());

    vector<int> d1(n);
    for(int i = 0, l = 0, r = -1;i < n;i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }

        d1[i] = k--;
        if(i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    vector<int> d2(n);
    for(int i = 0, l = 0, r = -1;i < n;i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while(i - k >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }

        d2[i] = k--;
        if(i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }

    cout << "For string " << s << endl;
    cout << "Odd palindrome array : ";
    for(int x : d1) cout << x << " ";
    cout << endl;

    cout << "Even palindrome array : ";
    for(int x : d2) cout << x << " ";
    cout << endl;


    return 0;
}
