#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,l;
    cin >> n >> m >> l;

    int arr[l];

    for(int i = 0;i < l;i++){
        cin >> arr[i];
    }

    int possiblities = 0;

   for(int i = 0;i < l;i++){
       int sum = arr[i];
       int temp = n-1;
       
       while(temp > 0){
           for(int j = 0;j < l;j++){
               
           }
       }

       if(sum % m == 0){
           possiblities++;
       }
   }

    printf("%d", possiblities);

    return 0;
}