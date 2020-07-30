/*************************************************************************
	> File Name: 392.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月22日 星期三 19时06分41秒
 ************************************************************************/
#include <algorithm>
#include <iostream>
using namespace std;

int n, m, num[100005], mmax;

int check(int mid) {
    int cnt = 1, now = 0;
    for(int i = 1; i < n; i++) {
        if(num[i] - num[now] >= mid) {
            cnt++;
            now = i;
        }
    }
    return cnt;
}

int func() {
    int l = 1, r = mmax;
    while(r != l) {
        int mid = (r + l + 1) / 2;
        int cnt = check(l + r + 1) / 2;
        if(cnt >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    mmax = num[n];
    cout << func() << endl;
    return 0;
}
