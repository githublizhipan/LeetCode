/*************************************************************************
	> File Name: 243.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月18日 星期一 20时27分17秒
 ************************************************************************/

#include<iostream>
using namespace std;
long long T, n;
struct Node {
    long long s, e, d, num;
} arr[200005];

long long count(long long mid, long long n) {
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        if (arr[i].s > mid) continue;
        if (arr[i].e <= mid) {
            sum += (arr[i].e - arr[i].s) / arr[i].d + 1;
        } else {
            sum += (mid - arr[i].s) / arr[i].d + 1;
        }
    }
    return sum;
}

long long check(long long mid, long long n) {
    return count(mid, n) % 2;
}

void solve() {
    cin >> n;
    long long l, r;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].e >> arr[i].d;
        if (i == 0) l = arr[i].s, r = arr[i].e;
        l = min(l, arr[i].s);
        r = max(r, arr[i].e);
    }
    long long mid, ans;
    while (l != r) {
        mid = (l + r) / 2;
        //cout << "mid:" << mid << " sum:" << ans << endl;
        if (check(mid, n)) r = mid;
        else l = mid + 1;
    }
    long long cnt = count(l, n) - count(l - 1, n);
    if (cnt % 2) {
        cout << l << " " << cnt << endl;
    } else {
        cout << "Poor QIN Teng:(\n";
    }
    return ;
}


int main() {
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
