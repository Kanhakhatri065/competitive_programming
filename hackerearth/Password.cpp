#include <iostream>

using namespace std;

bool checkPalindrome(string firstStr, string secondStr) {
    int flag = true;

    if(firstStr.length() != secondStr.length()) {
        return false;
    }

    for(int i = 0;i < firstStr.length();i++){
        if(firstStr[i] != secondStr[firstStr.length() - 1 - i]){
            flag = false;
            break;
        }
    }

    return flag;
}

int main() {
    int list_size;
    cin >> list_size;

    string arr[list_size];
    for(int i = 0;i < list_size;i++){
        cin >> arr[i];
    }

    int flag = 0;
    int index = 0;
    for(int i = 0;i < list_size - 1;i++){
        index = i;
        for(int j = i + 1;j < list_size;j++){
            if(checkPalindrome(arr[i],arr[j])){
                break;
            }
        }
    }

    cout << arr[index].size() << " " << arr[index][arr[i].size() / 2] << endl;
    return 0;
}