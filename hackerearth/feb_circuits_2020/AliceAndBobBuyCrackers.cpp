#include <bits/stdc++.h>

using namespace std;

void subsetsUtil(vector<int>& A, vector<vector<int>>& res,vector<int>& subset, int index){
    res.push_back(subset);

    for(int i = index;i < A.size();i++){
        subset.push_back(A[i]);
        subsetsUtil(A, res, subset, i + 1);
        subset.pop_back();
    }
    return;
}

vector<vector<int>> subsets(vector<int>& A){
    vector<int>subset;
    vector<vector<int>> res;
    int index = 0;
    subsetsUtil(A, res, subset, index);
    
    return res;
}


int main(){
    int size;
    cin >> size;
    
    vector<int> arr;
    int temp;
    for(int i = 0;i < size;i++){
        cin >> temp;
        arr.push_back(temp);
    }

    vector<vector<int>> res = subsets(arr);
    vector<int> sum_store;

    for(int i = 0;i < res.size();i++){
        
    
        long long int sum = 0;
        for(int j = 0;j < res[i].size();j++){
            sum += res[i][j];
        }
        if(sum % 2 == 0 && sum /2 != 0){
            sum_store.push_back(sum);
        }
    }
    sort(sum_store.begin(),sum_store.end());
        
    vector<int>::iterator ip;

    ip = unique(sum_store.begin(), sum_store.begin() + sum_store.size());
    sum_store.resize(distance(sum_store.begin(),ip));

    cout << sum_store.size() << endl;
    
    return 0;
}