/*************************************************************************
	> File Name: 2456.Aggressivecows.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Wed Nov 11 09:22:51 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100050

int n, c, x[MAXN];

int check(int mid) {
    int cnt = 1, temp = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] - temp >= mid) {
            cnt++;
            temp = x[i];
            if (cnt >= c) return 1;
        }
    }
    return 0;
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n);
    int l = 0, r = x[n - 1] - x[0];
    while (l != r) {
        int mid = (l + r + 1) / 2;
        //cout << "l:" << l << " r:" << r << " mid:" << mid;
        if (check(mid)) {
            l = mid;   
            //cout << "true" << endl;
        } else {
            r = mid - 1;
            //cout << "false" << endl;
        }
    }
    cout << l << endl;
    return 0;
}
