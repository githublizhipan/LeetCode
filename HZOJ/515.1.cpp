/*************************************************************************
	> File Name: 515.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月22日 星期五 14时41分51秒
 ************************************************************************/

#include<iostream>
using namespace std;
int A, B, L, a, b;
double ans = 0x3f3f3f3f;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    cin >> A >> B >> L;
    double r = 1.0 * A / B;
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            double now = 1.0 * i / j;
            if (now >= r && now - r < ans - r && gcd(i, j) == 1) {
                ans = now;
                a = i;
                b = j;
            }
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
