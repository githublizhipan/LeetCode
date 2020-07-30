/*************************************************************************
	> File Name: 379.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 15时21分44秒
 ************************************************************************/ 
#include <stack>
#include<iostream>
using namespace std;
int main() {
    long long N, x, m, t = 0;
    stack<long long> s, smax;
    cin >> N;
    while(N--) {
        cin >> x;
        if(x == 0) {
            cin >> m;
            s.push(m);
            if(smax.size() == 0) {
                smax.push(m);
            } else if(m > smax.top()) {
                smax.push(m);
            }
        } else if(x == 1) {
            if(s.size() == 0) continue;
            if(s.top() == smax.top()) smax.pop();
            s.pop();
        } else if(x == 2) {
            if(s.size() == 0) {
                cout << 0 << endl;
                continue;
            }
            cout << smax.top() << endl;
        }
    }
    return 0;
}

