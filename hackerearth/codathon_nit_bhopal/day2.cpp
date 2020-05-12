#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int matrix[n][n];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> matrix[i][j];
        }
    }

    int query;
    cin >> query;

    for(int i = 1;i<=query;i++){
        int type,a,b,c;
        cin >> type >> a >> b >> c;
        
        for(int j = a-1;j < b;j++){
            if(matrix[j][j] == c){
                matrix[j][j] = 0;
            } else {
                matrix[j][j] = matrix[j][j] ^ c;
            }
        }
    }

    int sum = 0;
    for(int i = 0;i < n;i++){
        sum = sum + matrix[i][i];
    }

    printf("%d",sum);

    return 0;
}