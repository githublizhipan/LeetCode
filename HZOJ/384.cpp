/*************************************************************************
	> File Name: 384.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 10时54分23秒
 ************************************************************************/
#include <algorithm>
#include<iostream>
#include <queue>

using namespace std;

int val(int n) {
    while(n) {
        if(n % 10 == 7) return 0;
        n /= 10;
    }
    return 1;
}
int main() {
    queue<int> q;
    int N, x, t;
    cin >> N >> x >> t;
    for(int i = x; i <= N; ++i) {
        q.push(i);
    }
    for(int i = 1; i <= x - 1; ++i) {
        q.push(i);
    }

    /*
    for(int i = 1; i <= N; ++i) {
        cout << q.front() << endl;
        q.pop();
    } 
    */

    while(q.size() > 1) {
        if(t % 7 == 0 || !val(t)) {
            q.pop();
        } else {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        t++;
    }
    cout << q.front() << endl;
    return 0;
}
