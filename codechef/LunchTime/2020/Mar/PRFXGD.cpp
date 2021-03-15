#include <iostream>
#include <map>
using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    string str;
    int atmost_deletions, atmost_present;
    for(int i = 0;i < testcases;i++) {
        cin >> str;
        cin >> atmost_deletions >> atmost_present;

        map<char, int> m;
        for(int j = 0;j < str.length();j++) {
            m[str[j]]++;
        }

        map<char, int>::iterator it;

        while(atmost_deletions != 0) {
            for(it = m.begin();it != m.end();++it) {
                if(atmost_deletions == 0) {
                    break;
                }

                if(it->second >= atmost_present) {
                    m[it->first]--;
                }
            }
        }

        int count = 0;
        for(it = m.begin();it != m.end();++it) {
            if(it->second <= atmost_present) {
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}