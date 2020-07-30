/*************************************************************************
	> File Name: 242.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 16时33分47秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
long long a[MAX_N + 5];
long long b[MAX_N + 5];
long long sum[MAX_N + 5];
long long n, m;
#define INF 0x3f3f3f3f


bool check(long long A) {
    for (long long i = 1; i <= n; i++) {
        b[i] = a[i] - A;
        sum[i] = b[i] + sum[i - 1];
    }
    long long Y = 0;
    for (long long j = m; j <= n; j++) {
        Y = min(Y, sum[j - m]);
        if (sum[j] - Y >= 0) return true;
    }
    return false;
}


long long bs(long l, long r) {
    if (l == r) return l;
    long long mid = (l + r + 1) >> 1;
    if (check(mid)) return bs(mid, r);
    return bs(l, mid - 1);
}


int main() {
    cin >> n >> m;
    long long l = INF, r = -INF;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 1000;
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    cout << bs(l, r) << endl;
    return 0;
}
