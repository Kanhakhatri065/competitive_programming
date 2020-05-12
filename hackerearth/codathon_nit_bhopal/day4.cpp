#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_cities;
    cin >> num_cities;

    int arr[num_cities-1][3];

    for(int i = 0;i < num_cities - 1;i++){
        cin >> arr[i][0]  >> arr[i][1] >> arr[i][2];
    }

    int num_queries;
    cin >> num_queries;

    for(int i = 0;i < num_queries;i++){
        int x;
        cin >> x;

        int possibilities = 0;
        for(int j = 0;j < num_cities - 1;j++){
            int trace = 0;

            if(arr[j][2] <= x){
                trace++;
                possibilities++;

                int temp = j;

                for(int k = 0;k < num_cities - 1;k++){

                    if(arr[temp][1] == arr[k][0]){

                        if(arr[k][2] <= x){
                            trace++;
                            temp = k;
                        }
                    }
                }

                if(trace > 1){
                    possibilities++;
                }
            }
        }
        cout << possibilities << endl;
    }

    return 0;
}