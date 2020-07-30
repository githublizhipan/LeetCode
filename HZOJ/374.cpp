/*************************************************************************
	> File Name: 374.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月02日 星期日 23时13分12秒
 ************************************************************************/
#include <cstring>
#include<iostream>
using namespace std;
int num[10];

int uniq(int n) {
    if(n < 123 || n > 999) return 0;
    int t = n % 10, p = (n / 10) % 10, q = n / 100;
    if(t && p && q && t != p && p != q) return 1;
    return 0;
}

int is_val(int a, int b, int c) {
    long long n = a * 1000000 + b * 1000 + c;
    memset(num, 0, sizeof(num));
    while(n) {
        if(num[n % 10]) return 0;
        num[n % 10] = 1;
        n /= 10;
    }
    return 1;
}

int main() {
    int x, y, z, a, b, c, flag = 1;
    cin >> x >> y >> z;
    for(int i = 123; i <= 987; ++i) {
        
        if(!uniq(i)) continue;
        a = i, b = a * y / x, c = a * z / x;
        if(!uniq(b) || !uniq(c)) continue;
        if(is_val(a, b, c)) {
            cout << a << " " << b << " " << c << endl;
            flag = 0;
        }
    }
    if(flag) cout << "No" << endl;
    return 0;
}

