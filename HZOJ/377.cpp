/*************************************************************************
	> File Name: 377.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 11时25分42秒
 ************************************************************************/
#include <stack>
#include<iostream>
using namespace std;
int main() {
    stack<char> s;
    char c;
    while(cin >> c, c != '@') {
        if(c == '(') {
            s.push(c);
        } else if(c == ')') {
            if(!s.empty()) s.pop();
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if(s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
