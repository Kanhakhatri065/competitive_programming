#include <iostream>

using namespace std;

int main() {
    int n, m, g;
    cin >> n >> m >> g;

    int time_to_rain[n];
    for(int i = 0;i < n;i++) {
        cin >> time_to_rain[i];
    }

    int time_taken[m];
    for(int i = 0;i < m;i++) {
        cin >> time_taken[i];
    }

    int count = 0;
    int initial_time = 0;
    for(int j = 0;j < n;j++) {
        for(int k = 0;k < m;k++) {
            if(time_to_rain[j] - initial_time >= time_taken[k] && time_taken[k] > 0) {
                count++;
                time_taken[k] = -1;
            }
        }
        initial_time = time_to_rain[j];
    }

    cout << count << endl;

    return 0;
}