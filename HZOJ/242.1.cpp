/*************************************************************************
	> File Name: 242.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月18日 星期一 17时39分37秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100005
long long n, m;
long long a[MAX_N], b[MAX_N], sum[MAX_N];
long long l, r;


long long check(long long x) {
    for (long long i = 1; i <= n; i++) {
        b[i] = a[i] - x;
        sum[i] = sum[i - 1] + b[i];
    }
    long long y = 0x3f3f3f3f;
    for (long long i = m; i <= n; i++) {
        y = min(y, sum[i - m]);
        if (sum[i] - y >= 0) return 1; 
    }
    return 0;
}


int main() {
    cin >> n >> m;
    l = 0x3f3f3f3f, r = -0x3f3f3f3f;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 1000;
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    while (l != r) {
        long long mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
