#include <iostream>
#include <stack>

using namespace std;

void showStack(stack<char> p){
    while(!p.empty()){
        cout << p.top();
        p.pop();
    }
}

int main(){
    int size;
    cin >> size;

    stack<char>s,p;
    s.push('\0');
    char x;
    for(int i = 0;i < size;i++){
        cin >> x;
        if(x == s.top()){
            s.pop();
        } else {
            s.push(x);
        }
    }

    while(!s.empty()){
        p.push(s.top());
        s.pop();
    }

    p.pop();

    cout << p.size() << endl;
    showStack(p);
    cout << endl;
    
    return 0;
}