/*************************************************************************
	> File Name: 589.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时42分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
int gcd(int n, int k) {
    if (k == 0) return n;
    return gcd(k, n % k);
}
int main() {
    int n, k, d;
    cin >> n >> k >> d;
    if (n == k) {
        cout << "1/1" << endl;
        return 0;
    } else if (k == 0) {
        cout << "0/1" << endl;
        return 0;
    }
    int g = gcd(n, k);
    cout << (k / g) << "/" << (n / g) << endl;
    return 0;
}
