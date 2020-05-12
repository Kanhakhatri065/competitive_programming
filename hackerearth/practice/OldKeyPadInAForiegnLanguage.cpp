#include <bits/stdc++.h>

using namespace std;

int main() {
    int frequency;
    cin >> frequency;

    int frequencies[frequency];
    for(int i = 0;i < frequency;i++) {
        cin >> frequencies[i];
    }

    int keySize;
    cin >> keySize;

    int count[51] = {0};
    for(int i = 0;i < keySize;i++) {
        int x;
        cin >> x;
        for(int j = 1;j <= x;j++) {
            count[j]++;
        }
    }

    sort(frequencies, frequencies + frequency);

    int answer = 0, j = frequency - 1;
    for(int i = 1;i <= 50;i++) {
        int sum = 0;
        while(count[i] >0 && j >= 0) {
            count[i]--;
            sum += frequencies[j];
            j--;
        }

        answer += sum * i;
        if(j == -1) {
            break;
        }
    }

    if(j != -1) {
        cout << "-1" << endl;
    } else {
        cout << answer << endl;
    }

    return 0;
}