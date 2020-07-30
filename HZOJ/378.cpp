/*************************************************************************
	> File Name: 378.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月11日 星期六 21时45分13秒
 ************************************************************************/
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
int main() {
    int flag = 0;
    char c;
    cin >> c;
    stack<char> s;
    while(c != '@') {
        if(c != '(' && c != '[' && c != '{' && c != ')' && c != ']' && c != '}') {
            cin >> c;
            continue;
        }
        if(c == '(' || c == '[' || c == '{') {
            s.push(c);
            cin >> c;
            continue;
        }
        if(c == ')') {
            if(s.top() == '(') s.pop();
            else {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if(c == ']') {
            if(s.top() == '[') s.pop();
            else {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if(c == '}') {                        
            if(s.top() == '{') s.pop();
            else {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        cin >> c;
    }
    //cout << s.empty() << endl;
    if(s.empty()) cout << "YES" << endl; 
    else if(!flag) cout << "NO" << endl;
    return 0;
}
