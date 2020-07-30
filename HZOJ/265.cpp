/*************************************************************************
	> File Name: 265.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 19时03分06秒
 ************************************************************************/
#include<stack>
#include<iostream>
using namespace std;
int main() {
    int n, m, maxlen = 0;
    char str[400005];
    cin >> n >> m >> str;

    stack<char> s;
    int l, r, cnt = 0;
    cin >> l >> r;
    for(int i = 0; str[i]; i++) {
        if(str[i] == '(') {
            s.push(str[i]);
        } else if(str[i] == ')') {
            if(s.empty()) continue;
            if(s.top() != '(') {
                maxlen = max(cnt, maxlen);
                cnt = 0;
                while(!s.empty()) s.pop();
                continue;
            }
            s.pop();
            cnt += 2;;
        }
       


        else {
        if(str[i] == '[') {
            s.push(str[i]);
        } else if(str[i] == ']') {
            if(s.empty()) continue;
            if(s.top() != '[') {
                maxlen = max(cnt, maxlen);
                cnt++;
                while(!s.empty()) s.pop();
                continue;
            }
            s.pop();
            cnt += 2;;
        }
            }
       

        if(str[i] == '{') {
            s.push(str[i]);
        } else if(str[i] == '}') {
            if(s.empty()) continue;
            if(s.top() != '{') {
                maxlen = max(cnt, maxlen);
                cnt++;
                while(!s.empty()) s.pop();
                continue;
            }
                cout << "...{{}}\n" ;
            s.pop();
            cnt += 2;;
        }
    }
    cout << maxlen << endl;
    return 0;
}
