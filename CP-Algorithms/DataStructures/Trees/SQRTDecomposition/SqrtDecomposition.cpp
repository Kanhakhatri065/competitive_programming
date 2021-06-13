#include <bits/stdc++.h>
using namespace std;

int main() {
    //Input data
    cout << "Enter the size of the array : " << endl;
    int n;
    cin >> n;
    cout << "Enter the elements of the array : " << endl;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    //Preprocessing
    cout << "Preprocessing started" << endl;
    int len = (int) sqrt(n + .0) + 1;
    vector<int> b(len);
    for(int i = 0;i < n;i++) b[i / len] += a[i];
    cout << "Preprocessing ended" << endl;

    cout << "enter the number of queries" << endl;
    int q;
    cin >> q;
    while(q--) {
        cout << "enter the range : " << endl;
        int l, r;cin >> l >> r;
        int sum = 0;
        for(int i = l;i <= r;) {
            if(i % len == 0 && i + len - 1 <= r) {
                sum += b[i / len];
                i += len;
            } else {
                sum += a[i];
                i++;
            }
        }

        cout << "Sum in the given range : " << sum << endl;
    }
}
