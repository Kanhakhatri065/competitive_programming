#include <bits/stdc++.h>

using namespace std;

int main(){
    int size;
    cin >> size;

    queue<int> calling, ideal;
    int temp;
    for(int i = 0;i < size;i++){
        cin >> temp;
        calling.push(temp);
    }

    for(int i = 0;i < size;i++){
        cin >> temp;
        ideal.push(temp);
    }

    int count = 0;
    while(calling.size() != 0 && ideal.size()!= 0){
        int i = calling.front();
        int j = ideal.front();
        if(i == j){
            calling.pop();
            ideal.pop();
            count++;
        } else {
            int k = calling.front();
            calling.pop();
            calling.push(k);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}