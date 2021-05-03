#include <bits/stdc++.h>
using namespace std;

string paragraph;

void solve(ofstream& fout) {
    string ret = "";
    int left = 0;
    for(int i = 0;i < paragraph.length();i++) {
        if(paragraph[i] == '/' && i + 1 < paragraph.length() && paragraph[i + 1] == '*') {
            left++;
            i++;
        } else if(left > 0 && paragraph[i] == '*' && i + 1 < paragraph.length() && paragraph[i + 1] == '/') {
            left--;
            i++;
        } else if(left == 0) {
            ret += paragraph[i];
        } else {
            continue;
        }
    }

    fout << ret.c_str();
}

int main() {
    FILE* fp = freopen("input.txt", "r", stdin);
    ofstream fout("output.txt");

    char ch;
    paragraph.clear();
    while(true) {
        cin.get(ch);
        if(cin.eof()) break;
        paragraph.push_back(ch);
    }

    fout << "Case #1:\n";
    solve(fout);


    return 0;
}