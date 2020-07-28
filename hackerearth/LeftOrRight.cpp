#include <bits/stdc++.h>

using namespace std;

int main() {
    int cities;
    long long int queries;
    cin >> cities >> queries;

    long long int arr[cities];
    for(int i = 0;i < cities;i++) {
        cin >> arr[i];
    }

    long long int query[queries][2];
    char directions[queries];

    for(long long int i = 0;i < queries;i++) {
        cin >> query[i][0] >> query[i][1] >> directions[i];
    }

    for(long long int i = 0; i < queries;i++) {
        long long int source_city_index = query[i][0];
        long long int destination_city_type = query[i][1];

        char direction = directions[i];

        if(direction == 'L') {
            bool type_does_not_exist = false;
            
            int destination_city_index = 0;
            for(int j = 0;j < cities;j++) {
                
                if(destination_city_type != arr[j] && j == cities - 1) {
                    type_does_not_exist = true;
                }

                if(destination_city_type == arr[j]) {
                    break;
                }

                destination_city_index++;
            }

            if(type_does_not_exist) {
                cout << "-1" << endl;
                continue;
            }

            if(destination_city_index <= source_city_index) {
                cout << (source_city_index - destination_city_index) << endl;
            } else {
                cout << (cities - destination_city_index + source_city_index) << endl;
            }
        } else {
            bool type_does_not_exist = false;
            
            int destination_city_index = 0;
            for(int j = 0;j < cities;j++) {
                
                if(destination_city_type != arr[j] && j == cities - 1) {
                    type_does_not_exist = true;
                }

                if(destination_city_type == arr[j]) {
                    break;
                }

                destination_city_index++;
            }

            if(type_does_not_exist) {
                cout << "-1" << endl;
                continue;
            }

            if(destination_city_index >= source_city_index) {
                cout << (destination_city_index - source_city_index) << endl;
            } else {
                cout << (cities - source_city_index + destination_city_index) << endl;
            }
        }
    }

    return 0;
}