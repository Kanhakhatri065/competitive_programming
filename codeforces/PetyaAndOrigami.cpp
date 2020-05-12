#include <iostream>

typedef long long int ll;
using namespace std;

int main() {
    ll friends, sheets_per_page;
    cin >> friends >> sheets_per_page;

    ll red_sheets = friends * 2;
    ll green_sheets = friends * 5;
    ll blue_sheets = friends * 8;

    ll count = 0;

    count += (red_sheets / sheets_per_page);
    if(red_sheets % sheets_per_page != 0) {
        count++;
    }

    count += (green_sheets / sheets_per_page);
    if(green_sheets % sheets_per_page != 0) {
        count++;
    }

    count += (blue_sheets / sheets_per_page);
    if(blue_sheets % sheets_per_page != 0) {
        count++;
    }

    cout << count << endl;

    return 0;
}