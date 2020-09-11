/*************************************************************************
	> File Name: 1995.RaisingModuloNumbers.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Wed Sep  9 22:04:46 2020
	> Source:  
 ************************************************************************/

#include<iostream>
using namespace std;

long long quick_mod(long long a, long long b, long long m) {
    long long ret = 1 % m;
    while (b) {
        if (b & 1) {
            ret *= a;
            ret %= m;
        }
        a *= a;
        a %= m;
        b >>= 1;
    }
    return ret;
}

int main() {
    long long z, m, h, ans;
    cin >> z;
    while (z--) {
        ans = 0;
        cin >> m >> h;
        long long a, b;
        for (int i = 0; i < h; i++) {
            cin >> a >> b;
            long long t = quick_mod(a, b, m);
            //cout << t << endl;
            ans += t;
            ans %= m;
        }
        cout << ans % m << endl;
    }
    return 0;
}
